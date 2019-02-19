LIB_CFG=dep/libs.mk
NAME=RTv1.bin
LIBDIR=$(realpath dep)
OS_D=$(WORKING_DIR)/$(shell uname)
include dep/gen.mk
export NAME

make: $(OBJS)
	make $(shell uname)_OS

MINGW64_NT-10.0_OS:
	gcc $(OBJS) $(INCLUDE) $(LIBPATHS) $(LINKS) -o $(NAME) -lmingw32 -lSDL2main -lSDL2
Darwin_OS:
	gcc $(OBJS) $(INCLUDE) $(LIBPATHS) $(LINKS) -o $(NAME)  -framework opengl -framework appkit -lmlx

