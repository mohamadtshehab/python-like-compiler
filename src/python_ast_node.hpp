/*
* @name python_ast_node.h
* @description Hierachy of AST
* @author Ismaeel_J_K 
* @example x=y+99
*                        |---------|
*                        | AstNode |
*                        |---------|
*                             |
*                             |
*                      |--------------|
*                      |    Assign    |
*                      |--------------|
*                          |        |
*                         |           |
*                        |              |
*                    |------------|   |--------------|
*                    |     x      |   |      Plus    |
*                    |------------|   |--------------|
*                                       |          |
*                                      |            |
*                                     |              |
*                           |-------------|     |-------------|
*                           |       y     |     |       99    |
*                           |-------------|     |-------------|
*                                       
*/

#ifndef AST_NODE_H
#define AST_NODE_H

#include <iostream>
#include <string>
#include <vector>
// #include <stdlib.h>

inline std::string dot_escape(const std::string& text) {
    std::string escaped;
    for (char ch : text) {
        if (ch == '\\' || ch == '"') escaped += '\\';
        if (ch == '\n') escaped += "\\n";
        else escaped += ch;
    }
    return escaped;
}

// Abstract base class for AST nodes
class AstNode {
public:
    std::string name = "undefined";   // String member variable with default value
    std::string label = "undefined";
    std::string value = "undefined";
    virtual void add(AstNode* node) = 0;
    virtual void print() const = 0;
    virtual ~AstNode() {}
};

class SetNode : public AstNode {
private:
    std::vector<AstNode*> elements;
public:
    explicit SetNode(const std::string& name) {
        this->name = name;
        this->label = "Set";
    }
    void add(AstNode* node) override {
        elements.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"Set\"]" << std::endl;
        for (const auto* element : elements) {
            std::cout << "\t" << name << " -> " << element->name << ";" << std::endl;
            element->print();
        }
    }
    ~SetNode() override {
        for (auto* element : elements) delete element;
    }
};

class UnaryExpressionNode : public AstNode {
private:
    std::string operation;
    AstNode* operand;
public:
    UnaryExpressionNode(const std::string& operation, AstNode* operand)
        : operation(operation), operand(operand) {
        this->name = "UnaryExpression_" + operand->name;
        this->label = operation;
    }
    void add(AstNode*) override {}
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << operation << "\"]" << std::endl;
        std::cout << "\t" << name << " -> " << operand->name << ";" << std::endl;
        operand->print();
    }
    ~UnaryExpressionNode() override { delete operand; }
};

// Composite node for representing function declare
class FunctionNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    FunctionNode(const std::string& name) {
        this->name = name;
        this->label = "Declare Fun";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label <<": "<<name<<"\"]" << std::endl;
        std::vector<AstNode*>::iterator it;
        // for (it = next.begin(); it != next.end(); ++it) {
        //     // example
        //     // Func -> args
        //     // Func -> body
        //     std::cout << "\t" << name << " -> " << (*it)->name << ";" << std::endl;
        //     (*it)->print();
        // }
        for (const auto& item : next) {
            std::cout << "\t" << name << " -> " << item->name << ";" << std::endl;
            item->print();
        }
    }
    ~FunctionNode() {
        for (const auto& arg : next) {
            delete arg;
        }
    }
};

class ClassNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    ClassNode(const std::string& name) {
        this->name = name;
        this->label = "ClassDeclaration";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label <<": "<<name<<"\"]" << std::endl;
        std::vector<AstNode*>::iterator it;
        for (const auto& item : next) {
            std::cout << "\t" << name << " -> " << item->name << ";" << std::endl;
            item->print();
        }
    }
    ~ClassNode() {
        for (const auto& arg : next) {
            delete arg;
        }
    }
};

class ClassBodyNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    ClassBodyNode(const std::string& name) {
        this->name = name;
        this->label = "Body";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        // std::vector<AstNode*>::iterator it;
        // for (it = next.begin(); it != next.end(); ++it) {
        //     std::cout << "\t" << name << " -> " << (*it)->name << ";" << std::endl;
        //     (*it)->print();
        // }
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~ClassBodyNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};
// base node for representing identifier ,will create object  from lexer
class IdentifierNode : public AstNode {
public:
    IdentifierNode(const std::string& name, const std::string& label, const std::string& value) {
        this->name = name;
        this->label = label;
        this->value = value; 
    }
    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << dot_escape(value) << "\"]" << std::endl;
    }
};

class StringNode : public AstNode {
public:
    StringNode(std::string name, std::string label, std::string value) {
        this->name = name;
        this->label = label;
        this->value = value; 
    }
    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << dot_escape(value) << "\"]" << std::endl;
    }
};

class CommentNode : public AstNode {
public:
    CommentNode(std::string name, std::string label, std::string value) {
        this->name = name;
        this->label = label;
        this->value = value; 
    }
    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << dot_escape(value) << "\"]" << std::endl;
    }
};

class KeywordNode : public AstNode {
public:
    KeywordNode(std::string name, std::string label, std::string value) {
        this->name = name;
        this->label = label;
        this->value = value; 
    }
    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << dot_escape(value) << "\"]" << std::endl;
    }
};

class MemberExpression : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    MemberExpression(AstNode* first, AstNode* second) {
        this->name = first->name + second->name;
        this->label = "MemberExpression";
        this->value = first->value + '.' + second->value;
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << std::endl;
        std::vector<AstNode*>::iterator it;
        for (const auto& item : next) {
            std::cout << "\t" << name << " -> " << item->name << ";" << std::endl;
            item->print();
        }
    }
};

class FunctionCall : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    FunctionCall(const std::string& name, AstNode* identifier) {
        this->name = name;
        this->label = "FunctionCall";
        this->value = identifier->value;
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << dot_escape(value) << "()" << "\"]" << std::endl;
        std::vector<AstNode*>::iterator it;
        for (const auto& item : next) {
            std::cout << "\t" << name << " -> " << item->name << ";" << std::endl;
            item->print();
        }
    }
};

class WhileNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    WhileNode(const std::string& name) {
        this->name = name;
        this->label = "While";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << dot_escape(value) << "()" << "\"]" << std::endl;
        std::vector<AstNode*>::iterator it;
        for (const auto& item : next) {
            std::cout << "\t" << name << " -> " << item->name << ";" << std::endl;
            item->print();
        }
    }
};

class ForNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    ForNode(const std::string& name) {
        this->name = name;
        this->label = "For";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << dot_escape(value) << "()" << "\"]" << std::endl;
        std::vector<AstNode*>::iterator it;
        for (const auto& item : next) {
            std::cout << "\t" << name << " -> " << item->name << ";" << std::endl;
            item->print();
        }
    }
};

class DelNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    DelNode(const std::string& name) {
        this->name = name;
        this->label = "Del";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~DelNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class ReturnNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    ReturnNode(const std::string& name) {
        this->name = name;
        this->label = "Return";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~ReturnNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};
class AssertNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    AssertNode(const std::string& name) {
        this->name = name;
        this->label = "Assert";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~AssertNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class YieldNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    YieldNode(const std::string& name) {
        this->name = name;
        this->label = "Yield";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~YieldNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class RaiseNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    RaiseNode(const std::string& name) {
        this->name = name;
        this->label = "Raise";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~RaiseNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class WithNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    WithNode(const std::string& name) {
        this->name = name;
        this->label = "With";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~WithNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class TryNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    TryNode(const std::string& name) {
        this->name = name;
        this->label = "Try";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~TryNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class ExceptNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    ExceptNode(const std::string& name) {
        this->name = name;
        this->label = "Except";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~ExceptNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class FinallyNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    FinallyNode(const std::string& name) {
        this->name = name;
        this->label = "Finally";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~FinallyNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class NonLocalNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    NonLocalNode(const std::string& name) {
        this->name = name;
        this->label = "NonLocal";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~NonLocalNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class GlobalNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    GlobalNode(const std::string& name) {
        this->name = name;
        this->label = "Global";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~GlobalNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class CaseNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    CaseNode(const std::string& name) {
        this->name = name;
        this->label = "Case";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~CaseNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class MatchNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    MatchNode(const std::string& name) {
        this->name = name;
        this->label = "Match";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~MatchNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class ImportNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    ImportNode(const std::string& name) {
        this->name = name;
        this->label = "Import";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~ImportNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class Arg : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    Arg(const std::string& name) {
        this->name = name;
        this->label = "Argument";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& arg : next) {
            std::cout << "\t" << name << " -> " << arg->name << ";" << std::endl;
            arg->print();
        }
    }
};

class Args : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    Args(const std::string& name) {
        this->name = name;
        this->label = "Arguments";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& arg : next) {
            std::cout << "\t" << name << " -> " << arg->name << ";" << std::endl;
            arg->print();
        }
    }
};

class BlockNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    BlockNode(const std::string& name) {
        this->name = name;
        this->label = "Block";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        // std::vector<AstNode*>::iterator it;
        // for (it = next.begin(); it != next.end(); ++it) {
        //     std::cout << "\t" << name << " -> " << (*it)->name << ";" << std::endl;
        //     (*it)->print();
        // }
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~BlockNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class MatchBlock : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    MatchBlock(const std::string& name) {
        this->name = name;
        this->label = "MatchBlock";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        // std::vector<AstNode*>::iterator it;
        // for (it = next.begin(); it != next.end(); ++it) {
        //     std::cout << "\t" << name << " -> " << (*it)->name << ";" << std::endl;
        //     (*it)->print();
        // }
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~MatchBlock() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class ClassBlock : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    ClassBlock(const std::string& name) {
        this->name = name;
        this->label = "ClassBlock";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        // std::vector<AstNode*>::iterator it;
        // for (it = next.begin(); it != next.end(); ++it) {
        //     std::cout << "\t" << name << " -> " << (*it)->name << ";" << std::endl;
        //     (*it)->print();
        // }
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~ClassBlock() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class EmptyNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    EmptyNode(const std::string& name) {
        this->name = name;
        this->label = "Empty";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~EmptyNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class StatementsNode : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    StatementsNode(const std::string& name) {
        this->name = name;
        this->label = "Statements";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << ": " << name << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~StatementsNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class AssignmentStatement : public AstNode {
private:
    std::vector<AstNode*> next;
public:
    AssignmentStatement(const std::string& name) {
        this->name = name;
        this->label = "assignment";
    }
    void add(AstNode* node) override {
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << label << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
        // for (const auto& stmt : next) {
        //     stmt->print();
        // }
    }
    ~AssignmentStatement() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

// Leaf node for representing numeric literals
class NumberNode : public AstNode {
public:
    int value;
    NumberNode(const std::string name, const std::string label, int value) {
        this->name = name;
        this->label = label;
        this->value = value; 
    }
    void add(AstNode* /*node*/) override {
        std::cerr << "Cannot add a child to a leaf node." << std::endl;
    }
    void print() const override {
        std::cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << std::endl;
    }
};

class ConditionalStatement : public AstNode {
private:
    std::vector<AstNode*> next;
    std::string condition;
public:
    ConditionalStatement(const std::string& cond, const std::string& name) {
        this->condition = cond;
        if(cond == "if"){
            this->name = "ConditionalStatement_" + name;
            this->label = cond;
        }
        if(cond == "elif"){
            this->name = "ConditionalStatement_" + name;
            this->label = cond;
        }
        if(cond == "else"){
            this->name = "ConditionalStatement_" + name;
            this->label = cond;
        }
    }
    void add(AstNode* node) override {    
        next.push_back(node);
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << condition << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~ConditionalStatement() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class BinaryExpressionNode : public AstNode {
private:
    std::vector<AstNode*> next;
    std::string operation;
    AstNode* left;
    AstNode* right;
public:
    BinaryExpressionNode(const std::string& op, AstNode* l, AstNode* r) {
        this->operation = op;
        this->left = l;
        this->right = r;
        next.push_back(l);
        next.push_back(r);
        if(op == "+"){
            this->name = "BinaryExpression_" + l->name + "PLUS" + r->name;
            this->label = "BinaryExpression_" + l->name + "PLUS" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "-"){
            this->name = "BinaryExpression_" + l->name + "MINUS" + r->name;
            this->label = "BinaryExpression_" + l->name + "MINUS" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "*"){
            this->name = "BinaryExpression_" + l->name + "MULTIPLY" + r->name;
            this->label = "BinaryExpression_" + l->name + "MULTIPLY" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "/"){
            this->name = "BinaryExpression_" + l->name + "DIVIDE" + r->name;
            this->label = "BinaryExpression_" + l->name + "DIVIDE" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "**"){
            this->name = "BinaryExpression_" + l->name + "POWER" + r->name;
            this->label = "BinaryExpression_" + l->name + "POWER" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "%"){
            this->name = "BinaryExpression_" + l->name + "MODULO" + r->name;
            this->label = "BinaryExpression_" + l->name + "MODULO" + r->name;
            this->value = l->value + r->value;
        }
    }
    void add(AstNode* node) override {
        if (!left){
            left = node;
            next.push_back(node);
        }
        else if (!right) {
            right = node;
            next.push_back(node);
        }
        else
            std::cerr << "Binary expression already has two children." << std::endl;
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << operation << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~BinaryExpressionNode() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};

class BinaryLogicalExpression : public AstNode {
private:
    std::vector<AstNode*> next;
    std::string operation;
    AstNode* left;
    AstNode* right;
public:
    BinaryLogicalExpression(const std::string& op, AstNode* l, AstNode* r) {
        this->operation = op;
        this->left = l;
        this->right = r;
        next.push_back(l);
        next.push_back(r);
        if(op == ">="){
            this->name = "BinaryLogicalExpression_" + l->name + "GREATERTHANOREQUAL" + r->name;
            this->label = "BinaryLogicalExpression_" + l->name + "GREATERTHANOREQUAL" + r->name;
            this->value = l->value + r->value;
        }
        if(op == ">"){
            this->name = "BinaryLogicalExpression_" + l->name + "GREATERTHAN" + r->name;
            this->label = "BinaryLogicalExpression_" + l->name + "GREATERTHAN" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "<="){
            this->name = "BinaryLogicalExpression_" + l->name + "LESSTHANOREQUAL" + r->name;
            this->label = "BinaryLogicalExpression_" + l->name + "LESSTHANOREQUAL" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "<"){
            this->name = "BinaryLogicalExpression_" + l->name + "LESSTHAN" + r->name;
            this->label = "BinaryLogicalExpression_" + l->name + "LESSTHAN" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "=="){
            this->name = "BinaryLogicalExpression_" + l->name + "EQUAL" + r->name;
            this->label = "BinaryLogicalExpression_" + l->name + "EQUAL" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "!="){
            this->name = "BinaryLogicalExpression_" + l->name + "NOTEQUAL" + r->name;
            this->label = "BinaryLogicalExpression_" + l->name + "NOTEQUAL" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "and"){
            this->name = "BinaryLogicalExpression_" + l->name + "AND" + r->name;
            this->label = "BinaryLogicalExpression_" + l->name + "AND" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "or"){
            this->name = "BinaryLogicalExpression_" + l->name + "OR" + r->name;
            this->label = "BinaryLogicalExpression_" + l->name + "OR" + r->name;
            this->value = l->value + r->value;
        }
        if(op == "not in" || op == "in" || op == "is not" || op == "is"){
            std::string suffix = op == "not in" ? "NOTIN" :
                                 op == "in" ? "IN" :
                                 op == "is not" ? "ISNOT" : "IS";
            this->name = "BinaryLogicalExpression_" + l->name + suffix + r->name;
            this->label = this->name;
            this->value = l->value + r->value;
        }
    }
    void add(AstNode* node) override {
        if (!left){
            left = node;
            next.push_back(node);
        }
        else if (!right){
            right = node;
            next.push_back(node);
        }
        else
            std::cerr << "Binary Logical expression already has two children." << std::endl;
    }
    void print() const override {
        std::cout << "\t" << name << " [label=\"" << operation << "\"]" << std::endl;
        for (const auto& stmt : next) {
            std::cout << "\t" << name << " -> " << stmt->name << ";" << std::endl;
            stmt->print();
        }
    }
    ~BinaryLogicalExpression() {
        for (const auto& stmt : next) {
            delete stmt;
        }
    }
};


class AST {
private:
    AstNode* root = nullptr;
public:
    AST(AstNode* r) : root(r) {}
    ~AST() {
        if (root != nullptr) {
            delete root;
            root = nullptr;
        }
    }
    void Print() {
        std::cout << "digraph G {" << std::endl;
        root->print();
        std::cout << "}" << std::endl;
    }
};
#endif
