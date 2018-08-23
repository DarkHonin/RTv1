include libs.mk
LIBDIR=$(realpath .)
ifdef LIB
TARGS=$(LIBDIR)/$(LIB)
else
TARGS=$(LIBRAIRIES)
endif
dep_build:
	@for i in $(LIBRAIRIES); do \
		echo "Making: $$i"; \
		make -C $$i LIBDIR=$(LIBDIR) -s; \
	done

dep_fclean:
	@echo -n "Cleaning"
	@for i in $(LIBRAIRIES); do \
		make -C $$i fclean -s;\
		echo -n "."; \
	done
	@echo Done

dep_re:
	@echo "Rebuilding..."
	@for i in $(TARGS); do \
		make -C $$i re LIBDIR=$(LIBDIR) -s ;\
	done