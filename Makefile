ROOT_DIR:=$(CURDIR)
export ROOT_DIR
SUBDIRS:= src
.PHONY: all
all:
	@for d in $(SUBDIRS); do \
	$(MAKE) -C $$d; \
	done