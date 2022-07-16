#include "FunctionsLibrary.h"

// Add information to linked list
void Add_to_list(node_lake** node, const char* LakeName, const char* Country_of_Lake, int Depth_of_Lake, float Salinity_of_Lake)
{
	int id = 1;
	node_lake* new_node;
	node_lake* indicator;
	// Create the first element of the linked list
	if (*node == NULL)
	{
		new_node = (node_lake*)malloc(sizeof(node_lake));
		// If memory allocation failed
		if (!new_node) {
			printf("Error! Not enough memory");
			exit(1);
		}
		// If the memory is allocated successfully, copy the entered data to the node
		new_node->id = 1;
		strncpy(new_node->LakeName, LakeName, 30);
		strncpy(new_node->LakeCountry, LakeCountry, 30);
		new_node->LakeDepth = LakeDepth;
		new_node->Salinity = Salinity;
		new_node->next = NULL;
		*node = new_node;
		return;
	}

	indicator = *node;
	while (indicator->next)
	{
		indicator = indicator->next;
		id++;
	}


	// Create the following nodes
	new_node = (node_lake*)malloc(sizeof(node_lake));

	if (!new_node) {
		printf("Error! Not enough memory");
		exit(1);
	}

	new_node->id = id + 1;
	strncpy(new_node->LakeName, LakeName, 30);
	strncpy(new_node->LakeCountry, LakeCountry, 30);
	new_node->LakeDepth = LakeDepth;
	new_node->Salinity = Salinity;
	new_node->next = NULL;

	indicator->next = new_node;
}


// Remove linked list from memory
void Delete_list_from_memory(node_lake** node) {
	node_lake* indicator = *node;

	while (indicator)
	{
		*node = indicator->next;
		free(indicator);
		indicator = *node;
	}
}


// Output to the console of all records
void Display_all_records(node_lake** node) {
	node_lake* indicator = *node;

	int i = 0;
	while (indicator)
	{
		printf("\nNumber: %d\nLake Name: %s\nCountry: %s\nDepth: %d meters\nSalinity in percent: %.1f\n\n",
			indicator->id, indicator->LakeName, indicator->LakeCountry, indicator->LakeDepth, indicator->Salinity);
		i++;

		indicator = indicator->next;
	}

	if (!i) printf("\nRecords not found\n\n");
}

// Display information about lakes less than 50 meters deep and salinity greater than 20%
void Display_records_by_characteristics(node_lake** node)
{
	node_lake* indicator = *node;

	int i = 0;
	while (indicator)
	{
		if (indicator->LakeDepth < 50 && indicator->Salinity > 20)
		{
			printf("\nNumber: %d\nLake Name: %s\nCountry: %s\nDepth: %d meters\nSalinity in percent: %.1f\n\n",
				indicator->id, indicator->LakeName, indicator->LakeCountry, indicator->LakeDepth, indicator->Salinity);
			i++;
		}

		indicator = indicator->next;
	}

	if (!i) printf("\nRecords not found\n\n");
}


// Writing a linked list to a file
bool Write_data_to_file(node_lake** node, const char* file)
{
	FILE* flp;

	if (!(flp = fopen(file, "w+")))
		return false;

	node_lake* indicator = *node;
	fprintf(flp, "%s", "Lake Name   Country   Depth   Salinity\n");
	while (indicator)
	{
		fprintf(flp, "%s   %s  %d    %.1f\n", indicator->LakeName, indicator->LakeCountry, indicator->LakeDepth, indicator->Salinity);
		indicator = indicator->next;
	}
	fclose(flp);
	return true;

}
