/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalguer <msalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:52:35 by blarger           #+#    #+#             */
/*   Updated: 2023/10/08 21:25:18 by msalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

// output.c
void	show_message(char *str);

// input.c
int		read_from_file(char *filename, char ***keys, char ***values);
int		clean_input_user(char *input);
char	*read_number_from_input(void);
char	*get_number_without_zeros(char *input);

// translate.c
void	translate(char *input, char **keys, char **values);

// string.c
void	free_list_string(char **list_string);
char	*copy_array(char *input, int start, int length);
int		ft_length(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*delete_left_zeros(char *input);

// dictionary.c
int		get_index_in_dictionary(char *key_dict, char **keys);
char	*get_number_left(char *input, int *length);
int		get_mask_index(char *input, char **keys, int length);
char	*apply_left_mask(char *input, int length_input, int length_mask);
char	*apply_right_mask(char *input, char *mask, int length_input,
			int length_mask);

// file.c
char	**create_arrays_number(char *buffer, char **number);
char	*extract_number(char **buffer);
char	**create_arrays_cadena(char *buffer, char **cadena);
char	*extract_cadena(char **buffer);
void	*find_next_word(char *buffer);
int		syntax_is_valid(char *buffer);
char	*ft_strdup(char *src);

#endif
