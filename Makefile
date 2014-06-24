.PHONY: clean All

All:
	@echo "----------Building project:[ replica - Debug ]----------"
	@$(MAKE) -f  "replica.mk"
clean:
	@echo "----------Cleaning project:[ replica - Debug ]----------"
	@$(MAKE) -f  "replica.mk" clean
