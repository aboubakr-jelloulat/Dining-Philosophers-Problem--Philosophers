/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:47:09 by ajelloul          #+#    #+#             */
/*   Updated: 2025/05/04 21:47:10 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_MACROS_H
# define PH_MACROS_H

/* Terminal text color codes for output */
# define RED                 "\033[31m"
# define CYAN                "\033[36m"
# define RESET               "\033[0m"

/* Error messages for invalid program arguments */
# define ERR_NUM_PHILOS      "\nERROR: Invalid number of philosophers\n\n"
# define ERR_TIME_TO_DIE     "\nERROR: Invalid time to die value\n\n"
# define ERR_TIME_TO_EAT     "\nERROR: Invalid time to eat value\n\n"
# define ERR_TIME_TO_SLEEP   "\nERROR: Invalid time to sleep value\n\n"
# define ERR_TIMES_MUST_EAT  "\nERROR: Invalid number of times must eat\n\n"

/* messages for philosopher actions */
# define MSG_FORK            "has taken a fork"
# define MSG_EAT             "is eating"
# define MSG_SLEEP           "is sleeping"
# define MSG_THINK           "is thinking"
# define MSG_DIED            "died"

#endif
