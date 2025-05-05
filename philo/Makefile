DTEAL       = \033[38;2;0;173;173m
BYELLOW     = \033[1;33m
BWHITE      = \033[1;37m
BPURPLE     = \033[1;35m
BCYAN       = \033[1;36m
BGREEN      = \033[1;32m
RESET       = \033[0m


# multi-line variable : 
# Because Makefiles normally allow only one line per variable. 
# If you try to write a multi-line string without define, make doesn't know how to handle the line breaks

define PHILO_ART
$(DTEAL)██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗██╗██████╗ ███████╗██████╗ ███████╗$(RESET)
$(DTEAL)██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██║██╔══██╗██╔════╝██╔══██╗██╔════╝$(RESET)
$(DTEAL)██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║██║██████╔╝█████╗  ██████╔╝███████╗$(RESET)
$(DTEAL)██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██║██╔═══╝ ██╔══╝  ██╔══██╗╚════██║$(RESET)
$(DTEAL)██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║██║██║     ███████╗██║  ██║███████║$(RESET)
$(DTEAL)╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝$(RESET)
endef

export PHILO_ART
# By default, Makefile variables are not passed to subshells unless you export them



NAME        = philo
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -fsanitize=thread
#PTHREAD     = -pthread
RM          = rm -rf


SRC_DIR     = src/
UTILS_DIR   = utils/
INC_DIR     = includes/


SRC_FILES   = philo.c init_philosophers.c parse_arguments_and_check.c dining_philos_problem.c  philo_actions.c solo_philo_handler.c
UTILS_FILES = atoi.c putstr_fd2.c system_time.c display.c ft_usleep.c properties.c


# containate the path  become a full source file

SRCS        = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS       = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
HEADERS     = $(addprefix $(INC_DIR), philo.h ph_macros.h ph_prototype.h ph_structs.h)

# All source files 
ALL_SRCS    = $(SRCS) $(UTILS)


OBJS        = $(ALL_SRCS:.c=.o)


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

# @echo "$$PHILO_ART" is executed inside a subshell 
# If you don't use export PHILO_ART, the ASCII art will not appear

clean:
	@$(RM) $(OBJS)
	@echo "$(BYELLOW)🧹 Objects cleaned!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BPURPLE)🧼 Executable removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re