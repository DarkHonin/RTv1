LIB_CFG=../libs.mk

NAME=lib3dft.a
include ../gen.mk
export NAME

make: $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIB MADE"