#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

MAKE	= make -C
SHELL	:= bash

# Default test values
ARG			?=
N_OK		= 0
N_KO		= 0 

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

UNAME 			= $(shell whoami)
NAME 			= push_swap
NAME_BONUS		= checker

### Message Vars
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_NORM 			= [$(MAG)Norminette$(D)]
_NORM_SUCCESS 	= $(GRN)=== OK:$(D)
_NORM_INFO 		= $(BLU)File no:$(D)
_NORM_ERR 		= $(RED)=== KO:$(D)
_SEP 			= =====================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH		= src
BONUS_PATH		= bonus
LIBS_PATH		= lib
BUILD_PATH		= .build
TEMP_PATH		= .temp
TESTS_PATH		= files
LIBFT_PATH		= $(LIBS_PATH)

FILES = main.c
FILES += basic_cmds.c
FILES += build_stack.c
FILES += costs.c
FILES += free.c
FILES += push_swap.c
FILES += sanity_check.c
FILES += sort_stack.c
FILES += optimize.c
FILES += utils.c

FILES_BONUS = main.c
FILES_BONUS += basic_cmds.c
FILES_BONUS += build_stack.c
FILES_BONUS += costs.c
FILES_BONUS += free.c
FILES_BONUS += push_swap.c
FILES_BONUS += sanity_check.c
FILES_BONUS += sort_stack.c
FILES_BONUS += optimize.c
FILES_BONUS += utils.c
FILES_BONUS += check_stack.c


SRC		= $(addprefix $(SRC_PATH)/, $(FILES))
SRC_BONUS		= $(addprefix $(BONUS_PATH)/, $(FILES_BONUS))

OBJS	= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
OBJS_BONUS	= $(SRC_BONUS:$(BONUS_PATH)/%.c=$(BUILD_PATH)/%.o)

TXT		= $(addprefix $(TEMP_PATH)/, $(TXT_NAMES))

LIBFT_ARC	= $(LIBFT_PATH)libft.a

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CC			= cc

CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -g

INC			= -I.

#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#

RM		= rm -rf
AR		= ar rcs
MKDIR_P	= mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

##@ push_swap Compilation Rules 🏗

all: deps $(BUILD_PATH) $(NAME) ## Compile Mandatory version

$(NAME): $(LIBFT_ARC) $(BUILD_PATH) $(OBJS) $(OBJS_BONUS) ## Compile Mandatory version
	@echo "$(YEL)Compiling $(MAG)$(NAME)$(YEL) mandatory version$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_PATH) -lft
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL)🖔$(D)]"
	@make --no-print-directory norm

$(NAME_BONUS): $(BUILD_PATH) $(LIBFT_ARC) $(OBJS_BONUS)
	@echo "[$(YEL)Compiling push_swap checker$(D)]"
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) -L $(LIBFT_PATH) -lft
	@echo "[$(_SUCCESS) compiling $(MAG)push_swap checker!$(D) $(YEL)🖔$(D)]"


bonus:	all $(NAME_BONUS)	## Compile Bonus version
	@echo "$(YEL)Compiling $(MAG)$(NAME)$(YEL) bonus version$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) -L $(LIBFT_PATH) -lft
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL)🖔$(D)]"
	@make --no-print-directory norm_bonus
	#
deps:		## Download/Update deps
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(YEL)[libft]$(D) folder found ✌️";  fi
	@echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"

-include $(BUILD_PATH)/%.d

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) -I $(LIBFT_PATH) -MMD -MP -c $< -o $@

$(BUILD_PATH)/%.o: $(BONUS_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) -MMD -MP -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(CYA)$(BUILD_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(TEMP_PATH):
	$(MKDIR_P) $(TEMP_PATH)
	@echo "* $(YEL)Creating $(CYA)$(TEMP_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(LIBFT_ARC):
	@$(MAKE) $(LIBFT_PATH)

get_libft:
	@echo "* $(CYA)Getting Libft submodule$(D)]"
	@if test ! -d "$(LIBFT_PATH)"; then \
		git clone git@github.com:lude-bri/libft_42_LP.git $(LIBFT_PATH); \
		echo "* $(GRN)Libft submodule download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)Libft submodule already exists ✌️"; \
	echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"; \
	fi

##@ Norm Rules

norm: $(TEMP_PATH)		## Run norminette test on source files
	@echo "$(CYA)$(_SEP)$(D)"
	@printf "${_NORM}: $(YEL)$(SRC_PATH)$(D)\n"
	@ls $(SRC_PATH) | wc -l > $(TEMP_PATH)/norm_ls.txt
	@printf "$(_NORM_INFO) $$(cat $(TEMP_PATH)/norm_ls.txt)\n"
	@printf "$(_NORM_SUCCESS) "
	@norminette $(SRC_PATH) | grep -wc "OK" > $(TEMP_PATH)/norm.txt; \
	if [ $$? -eq 1 ]; then \
		echo "0" > $(TEMP_PATH)/norm.txt; \
	fi
	@printf "$$(cat $(TEMP_PATH)/norm.txt)\n"
	@if ! diff -q $(TEMP_PATH)/norm_ls.txt $(TEMP_PATH)/norm.txt > /dev/null; then \
		printf "$(_NORM_ERR) "; \
		norminette $(SRC_PATH) | grep -v "OK"> $(TEMP_PATH)/norm_err.txt; \
		cat $(TEMP_PATH)/norm_err.txt | grep -wc "Error:" > $(TEMP_PATH)/norm_errn.txt; \
		printf "$$(cat $(TEMP_PATH)/norm_errn.txt)\n"; \
		printf "$$(cat $(TEMP_PATH)/norm_err.txt)\n"; \
	else \
		printf "[$(YEL)Everything is OK$(D)]\n"; \
	fi
	@echo "$(CYA)$(_SEP)$(D)"

norm_bonus: 		## Run norminette test on chcker files
	@printf "${_NORM}: $(YEL)$(BONUS_PATH)$(D)\n"
	@ls $(BONUS_PATH) | wc -l > $(TEMP_PATH)/norm_ls.txt
	@printf "$(_NORM_INFO) $$(cat $(TEMP_PATH)/norm_ls.txt)\n"
	@printf "$(_NORM_SUCCESS) "
	@norminette $(BONUS_PATH) | grep -wc "OK" > $(TEMP_PATH)/norm.txt; \
	if [ $$? -eq 1 ]; then \
		echo "0" > $(TEMP_PATH)/norm.txt; \
	fi
	@printf "$$(cat $(TEMP_PATH)/norm.txt)\n"
	@if ! diff -q $(TEMP_PATH)/norm_ls.txt $(TEMP_PATH)/norm.txt > /dev/null; then \
		printf "$(_NORM_ERR) "; \
		norminette $(BONUS_PATH) | grep -v "OK"> $(TEMP_PATH)/norm_err.txt; \
		cat $(TEMP_PATH)/norm_err.txt | grep -wc "Error:" > $(TEMP_PATH)/norm_errn.txt; \
		printf "$$(cat $(TEMP_PATH)/norm_errn.txt)\n"; \
		printf "$$(cat $(TEMP_PATH)/norm_err.txt)\n"; \
	else \
		printf "[$(YEL)Everything is OK$(D)]\n"; \
	fi

check_ext_func: all		## Check for external functions
	@echo "[$(YEL)Checking for external functions$(D)]"
	@echo "$(YEL)$(_SEPcmd)$(D)"
	@echo "$(CYA)Reading binary$(D): $(MAG)$(NAME)$(D)"
	nm ./$(NAME) | grep "U" | grep -v "__" | tee $(TEMP_PATH)/ext_func.txt
	@echo "$(YEL)$(_SEP)$(D)"

##@ Test Rules 🧪

##@ Debug Rules 

gdb: all $(NAME) $(TEMP_PATH)			## Debug w/ gdb
	tmux split-window -h "gdb --tui --args ./$(NAME)"
	tmux resize-pane -L 5
	make get_log

vgdb: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck) & gdb
	tmux split-window -h "valgrind --vgdb-error=0 --log-file=gdb.txt ./$(NAME) $(ARG)"
	make vgdb_pid
	tmux split-window -v "gdb --tui -x $(TEMP_PATH)/gdb_commands.txt $(NAME)"
	tmux resize-pane -U 18
	make get_log

valgrind: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck)
	tmux set-option remain-on-exit on
	tmux split-window -h "valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME) $(ARG)"

helgrind: all $(NAME) $(TEMP_PATH)			## Debug threads w/ helgrind
	tmux set-option remain-on-exit on
	tmux split-window -h "valgrind --log-file=gdb.txt --tool=helgrind -s ./$(NAME) $(ARG7)"
	tmux resize-pane -R 55
	make get_log

vgdb_helgrind: all $(NAME) $(TEMP_PATH)			## Debug threads w/ helgrind & gdb
	tmux split-window -h "valgrind --vgdb-error=0 --log-file=gdb.txt --tool=helgrind ./$(NAME) $(ARG)"
	make vgdb_pid
	tmux split-window -v "gdb --tui -x $(TEMP_PATH)/gdb_commands.txt $(NAME)"
	tmux resize-pane -U 18
	make get_log

massif: all $(TEMP_PATH)		## Run Valgrind w/ Massif (gather profiling information)
	@TIMESTAMP=$(shell date +%Y%m%d%H%M%S); \
	if [ -f massif.out.* ]; then \
		mv -f massif.out.* $(TEMP_PATH)/massif.out.$$TIMESTAMP; \
	fi
	@echo " 🔎 [$(YEL)Massif Profiling$(D)]"
	valgrind --tool=massif --time-unit=B ./$(NAME) $(ARG)
	ms_print massif.out.*
# Learn more about massif and ms_print:
### https://valgrind.org/docs/manual/ms-manual.html

get_log:
	touch gdb.txt
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

vgdb_pid: $(NAME) $(TEMP_PATH)
	printf "target remote | vgdb --pid=" > $(TEMP_PATH)/gdb_commands.txt
	printf "$(shell pgrep -f valgrind)" >> $(TEMP_PATH)/gdb_commands.txt

##@ Clean-up Rules 󰃢

clean: 				## Remove object files
	@echo "* $(YEL)Removing $(MAG)$(NAME)$(D) and deps $(YEL)object files$(D)"
	@if [ -d "$(LIBFT_PATH)/$(BUILD_PATH)" ] || [ -d "$(BUILD_PATH)" ] || [ -d "$(TEMP_PATH)" ]; then \
		if [ -d "$(LIBFT_PATH)/$(BUILD_PATH)" ]; then \
			$(MAKE) $(LIBFT_PATH) clean; \
			echo "* $(YEL)Removing $(CYA)libft$(D) object files$(D): $(_SUCCESS)"; \
		fi; \
		if [ -d "$(BUILD_PATH)" ]; then \
			$(RM) $(BUILD_PATH); \
			echo "* $(YEL)Removing $(CYA)$(BUILD_PATH)$(D) folder & files$(D): $(_SUCCESS)"; \
		fi; \
		if [ -d "$(TEMP_PATH)" ]; then \
			$(RM) $(TEMP_PATH); \
			echo "* $(YEL)Removing $(CYA)$(TEMP_PATH)$(D) folder & files:$(D) $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to clean!$(D)]"; \
	fi

fclean: clean libclean			## Remove executable and .gdbinit
	@if [ -f "$(NAME)" ]; then \
		if [ -f "$(NAME)" ]; then \
			$(RM) $(NAME); \
			echo "* $(YEL)Removing $(CYA)$(NAME)$(D) file: $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to be fcleaned!$(D)]"; \
	fi

libclean: fclean	## Remove libs
	$(RM) $(LIBS_PATH)
	@echo "* $(YEL)Removing lib folder & files!$(D) : $(_SUCCESS)"

re: fclean all	## Purge & Recompile

##@ Help 󰛵

help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(D)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-18s$(D) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile
## Tweaked from source:
### https://www.padok.fr/en/blog/beautiful-makefile-awk

.PHONY: bonus clean fclean re help

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
