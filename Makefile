PROJECT:=exception
PROJECT_INCLUDE_DIR:=include

INSTALL_TOP:=/usr/local
INSTALL_INC:=$(INSTALL_TOP)/include/$(PROJECT)

.PHONY: install uninstall

# Any of the following make rules can be executed with the `-j` option (`make -j`) for parallel compilation 

install:
	mkdir -p $(INSTALL_INC)
	install -p -m 0644 $(PROJECT_INCLUDE_DIR)/$(PROJECT)/*.hpp $(INSTALL_INC)

uninstall:
	$(RM) -R $(INSTALL_INC)
