LIB_CFG=dep/libs.mk
NAME=RTv1.bin
LIBDIR=$(realpath dep)
OS_D=$(WORKING_DIR)/$(shell uname)
include dep/gen.mk
export NAME

make: $(OBJS)
	gcc $(OBJS) $(INCLUDE) $(LIBPATHS) $(LINKS) -o $(NAME)  -lmingw32 -lSDL2main -lSDL2  # -framework opengl -framework appkit -lmlx
