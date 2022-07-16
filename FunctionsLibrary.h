#ifndef FUNCTIONSLIBRARY_H
#define FUNCTIONSLIBRARY_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct node {
	int id;
	char* Name_of_Lake[30];
	char* Country_of_Lake[30];
	int Depth_of_Lake;
	float Salinity_of_Lake;
	struct node* next;
} node_lake;

void Add_to_list(node_lake** node, const char* Name_of_Lake, const  char* Country_of_Lake, int Depth_of_Lake, float Salinity_of_Lake);

void Delete_list_from_memory(node_lake** node);

void Display_all_records(node_lake** node);

void Display_records_by_characteristics(node_lake** node);

#endif
