/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 19:11:02 by sprodan-          #+#    #+#             */
/*   Updated: 2017/09/18 01:21:53 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		last_stars(int size)
{
	int level;
	int floor;
	int top;
	int star;
	int incr;

	level = 1;
	floor = 3;
	star = 1;
	incr = 2;
	while (level <= size)
	{	
		top = 1;
		if (level % 2 == 0)
			incr = incr + 2;
		if (level != 1)
			star = star + incr;
		while (top++ <= floor)
			star = star + 2;
		floor++;
		level++;
	}
	return (star);
}

int		door(int size)
{	
	int h;

	if (size % 2 == 0)
		h = size -1;
	else
		h = size;
	return (h);
}

int		door2(int i, int st, int size, int top, int floor)
{
	int incr;
	int h;

	h = door(size);	
	i = st;	
	while (i > 0)
	{
		if (i == st / 2 + h / 2 + 1 && top >= floor - h + 1)
		{	
			incr = 1;
			while (incr <= h)
			{
				if (top == floor - h / 2 && incr == h - 1 && size > 4)
					printf("$");
				else
					printf("|");
				i--;
				incr++;
			}
		}
		i--;
		printf("*");
	}
	return (i);
}

void put_line(int a, int st, int level, int top, int floor, int size) 
{
	int incr2;
	int i;

	incr2 = 1;
	while (incr2++ <= a)
		printf(" ");
	printf("/");
	i = st;
	if (level == size)
		i =	door2(i, st, level, top, floor);
	while (i-- > 0)
		printf("*");
	printf("\\");
	printf("\n");
}

int main (void)
{
	int size;
	int level;
	int floor;
	int incr;
	int st;
	int top;
	int a;

	size = 5;
	level = 1;
	floor = 3;
	incr = 2;
	st = 1;
	a = last_stars(size) / 2 - 1;
	while (level <= size)
	{
		if (level % 2 == 0)
			incr = incr + 2;
		if (level != 1)
		{
			st = st + incr;
			a = a - incr / 2;
		}
		top = 1;
		while (top <= floor)
		{
			put_line(a, st, level, top, floor, size);
			st = st + 2;
			a--;
			top++;
		}
		floor++;
		level++;
	}
	return (0);
}
