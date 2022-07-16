/**
* @file SummerPratice
* @author Сидоренко В. П.  515в
* @date 14 липня 2022
* @brief Ë³òíÿ ïðàêòèêà
*
* Ñòâîðåííÿ òåêñòîâîãî ôàéëó íà 12 çàïèñ³â ç ³íôîðìàö³ºþ ïðî îçåðà
*/
#include "FunctionsLibrary.h"

int main(int argc, char* argv[]) {
	
	node_lake* node;
	node = NULL;

	FILE* flp;
	char file[] = "lakes.txt";

	char Name_of_Lake[30];
	char Country_of_lake[30];
	int Depth_of_Lake;
	float Salinity_of_Lake;

	bool Input;
	bool Result;

	int choice;
	int i = 0;

	if (flp = fopen(file, "r")) {
		fseek(flp, 38, SEEK_SET);

		while (fscanf(flp, "%s%s%d%f" &Name_of_Lake, Country_of_Lake, &Depth_of_Lake, &Salinity_of_Lake) != EOF) {
			if (Depth_of_Lake <= 0 || Salinity_of_Lake < 0 || Salinity_of_Lake > 100) {
				printf("Error! Incorrect information in the file\n");
				Input = false;
				break;
			}
				Add_to_list(&node, Name_of_Lakr, Country_of_Lake, Depth_of_Lake, Salinity_of_Lake);
				Salinity_of_Lake = -1;
				i++;
		}

		fclose(flp);
		if (i == 12) {
			printf("Data from lakes.txt file loaded successfully\n\n");
			Result = true;
		}
		else {
			printf("The file must contain exclusively 12 records with correct information about the lakes\n");
			Delete_list_from_memory(&node);
			Result = false;
		}
	}

	while (true) {
		printf("====Functions====");
		printf("\n1.Display the entire list");
		printf("\n2.Display information about lakes less than 50 meters deep and salinity greater than 20 percent");
		printf("\n3.Exit");
		printf("\nEnter the number of the feature you want to use: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: Display_all_records(&node); break;
		case 2: Display_records_by_characteristics(&node); break;
		case 3: exit(EXIT_SUCCESS); break;
		default: printf("\nInvalid operation number\n\n"); break;
		}
	}
}