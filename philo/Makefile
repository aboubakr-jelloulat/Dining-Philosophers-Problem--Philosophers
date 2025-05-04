# Colors for terminal output
DTEAL       = \033[38;2;0;173;173m
BYELLOW     = \033[1;33m
BWHITE      = \033[1;37m
BCYAN       = \033[1;36m
BGREEN      = \033[1;32m
RESET       = \033[0m


# ASCII Art for philosophers
define PHILO_ART
$(DTEAL)██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗██╗██████╗ ███████╗██████╗ ███████╗$(RESET)
$(DTEAL)██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██║██╔══██╗██╔════╝██╔══██╗██╔════╝$(RESET)
$(DTEAL)██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║██║██████╔╝█████╗  ██████╔╝███████╗$(RESET)
$(DTEAL)██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██║██╔═══╝ ██╔══╝  ██╔══██╗╚════██║$(RESET)
$(DTEAL)██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║██║██║     ███████╗██║  ██║███████║$(RESET)
$(DTEAL)╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝$(RESET)
endef

export PHILO_ART

# Project configuration
NAME        = philo
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
PTHREAD     = -pthread
RM          = rm -rf

# Directories
SRC_DIR     = src/
UTILS_DIR   = utils/
INC_DIR     = includes/

# Source files
SRC_FILES   = philo.c init_philosophers.c parse_arguments_and_check.c
UTILS_FILES = atoi.c putstr_fd2.c system_time.c

# Full paths
SRCS        = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS       = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
HEADERS     = $(addprefix $(INC_DIR), philo.h ph_macros.h ph_prototype.h ph_structs.h)

# All source files 
ALL_SRCS    = $(SRCS) $(UTILS)

# Object files 
OBJS        = $(ALL_SRCS:.c=.o)

# Rules
all: $(NAME)

# Compile each source file
%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(BCYAN)Compiling:$(RESET) $<"

# Link the executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $(NAME)
	@echo "$(BGREEN)✅ $(NAME) successfully compiled!$(RESET)"
	@echo "$${PHILO_ART}"

clean:
	@$(RM) $(OBJS)
	@echo "$(BYELLOW)🧹 Objects cleaned!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BPURPLE)🧼 Executable removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re