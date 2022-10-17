# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 13:45:18 by yongmkim          #+#    #+#              #
#    Updated: 2022/09/09 17:21:01 by yongmkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

ifndef NAME
	NAME	= a.out
endif

ifndef SRC
	SRC		=
endif

SRC_DIR		=
OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INC_DIR		=
LIB_LNK		=	-I $(INC_DIR)

#==============================================================================
#	Compile Flags
#==============================================================================
CXX			=	c++
CXX_WARN_FLAGS	=	all extra error
CXX_STD_FLAGS	=	c++98
CXXFLAGS	+=	$(addprefix -W, $(CXX_WARN_FLAGS))
CXXFLAGS	+=	$(addprefix -std=, $(CXX_STD_FLAGS))
CXXFLAGS	+=	-pedantic
CXXFLAGS	+=	-g
CXXFLAGS	+=	-fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
# CXXFLAGS	+=	-fsanitize=address -fsanitize=undefined
# CXXFLAGS	+=	-fsanitize=address

RM			=	rm -f

DEBUG		=	-g
SNTZ		=	-fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
MEM			=	-fsanitize=memory -fsanitize-memory-track-origins \
				-fPIE -pie -fno-omit-frame-pointer
LEAK		=	-fsanitize=leak

#==============================================================================
#	Make Part
#==============================================================================
.PHONY		:	all clean fclean re
all			:	$(NAME)
clean		:	; $(RM) -r $(OBJ_DIR)
fclean		:	clean ; $(RM) $(NAME)
re			:
		make fclean
		make all

$(NAME)		:	$(OBJ)
		$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)	:
		mkdir -p $(OBJ_DIR)

$(OBJ)		:	| $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp $(INC_DIR)
		$(CXX) $(CXXFLAGS) -o $@ -c $<
