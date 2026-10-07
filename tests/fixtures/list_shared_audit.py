def list_shared_audit(
        self,
        principal,
        entity_type,
        entity_id,
        limit,
        offset,
    ):
        self._shared_actor(principal, Capability.MANAGE_CATALOGUE)
        if (
            entity_type not in {"Unit", "Stockable"}
            or type(limit) is not int
            or not 1 <= limit <= 100
            or type(offset) is not int
            or offset < 0
        ):
            raise records.InvalidCatalogue("Invalid audit page")
        return self._inventory.list_shared_audit(entity_type, entity_id, limit, offset)
