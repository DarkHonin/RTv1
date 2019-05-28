NAME=RTv1.bin
LIBDIR=$(realpath dep)
OS:=$(shell uname)
SRC_DIR:=${OS}
GEN_PATH=$(shell find ~/ -name "gen.mk" -type f)
LIB_CFG=$(shell find ~/ -name "libs.mk" -type f)
-include $(GEN_PATH)
export NAME
export SRC_DIR

make: $(OBJS)
	@echo making for $(OS)
	make $(OS)_OS

MINGW64_NT-10.0_OS:
	gcc $(OBJS) $(INCLUDE) $(LIBPATHS) $(LINKS) -o $(NAME) -lmingw32 -lSDL2main -lSDL2
Darwin_OS:
	gcc $(OBJS) $(INCLUDE) $(LIBPATHS) $(LINKS) -o $(NAME)  -framework opengl -framework appkit -lmlx

setup:
ifeq (${LIB_CFG}, )
	@echo "Downloading standard lib cfg file from 'https://raw.githubusercontent.com/DarkHonin/makefile_assets/master/libs.mk'";
	@curl -0 'https://raw.githubusercontent.com/DarkHonin/makefile_assets/master/libs.mk' -o ~/libs.mk -L;
	@echo "Download done";
else
	@echo Found lib config ${LIB_CFG}
endif
ifeq (${GEN_PATH}, )
	@echo "Downloading standard lib gen file from 'https://raw.githubusercontent.com/DarkHonin/makefile_assets/master/gen.mk'"; 
	@curl -0 'https://raw.githubusercontent.com/DarkHonin/makefile_assets/master/gen.mk' -o ~/gen.mk -L;
	@echo "Download done"; 
else 
	@echo "Lib generator file found $(GEN_PATH)"; 
endif