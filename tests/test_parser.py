from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[1]
COMPILER = ROOT / "build" / "compiler"
FIXTURE = ROOT / "tests" / "fixtures" / "list_shared_audit.py"
TYPED_FIXTURE = ROOT / "tests" / "fixtures" / "list_shared_audit_typed.py"


class ParserTests(unittest.TestCase):
    def run_compiler(self, *args, input_text=None):
        return subprocess.run(
            [str(COMPILER), *map(str, args)],
            input=input_text,
            text=True,
            capture_output=True,
            timeout=5,
            check=False,
        )

    def test_multiline_function_and_graph(self):
        result = self.run_compiler(FIXTURE)
        self.assertEqual(result.returncode, 0, result.stderr)
        for label in (
            'label="Set"',
            'label="not in"',
            'label="is not"',
            'label="not"',
            'FunctionCall: self._inventory.list_shared_audit()',
            'Return:',
        ):
            self.assertIn(label, result.stdout)

        if shutil.which("dot"):
            rendered = subprocess.run(
                ["dot", "-Tsvg"],
                input=result.stdout,
                text=True,
                capture_output=True,
                timeout=5,
                check=False,
            )
            self.assertEqual(rendered.returncode, 0, rendered.stderr)

    def test_stdin(self):
        result = self.run_compiler(input_text="x = 1\n")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn('label="assignment"', result.stdout)

    def test_typed_multiline_parameter(self):
        result = self.run_compiler(TYPED_FIXTURE)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn('Identifier: principal', result.stdout)
        self.assertIn('Identifier: int', result.stdout)
        self.assertIn('FunctionCall: self._inventory.list_shared_audit()', result.stdout)

        if shutil.which("dot"):
            rendered = subprocess.run(
                ["dot", "-Tsvg"],
                input=result.stdout,
                text=True,
                capture_output=True,
                timeout=5,
                check=False,
            )
            self.assertEqual(rendered.returncode, 0, rendered.stderr)

    def test_invalid_input_exits_with_error(self):
        result = self.run_compiler(input_text="x = ")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("Parser error:", result.stderr)

    def test_missing_file_exits_with_error(self):
        with tempfile.TemporaryDirectory() as directory:
            result = self.run_compiler(Path(directory) / "missing.py")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("Cannot open input file:", result.stderr)


if __name__ == "__main__":
    unittest.main()
