
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<time.h>
#include<dos.h>


struct info {
	char name[20];
	int ID;
};

void game(struct info *player,int num);

void call(struct info* player, int num);
void pause(void);
void clearKeyboard(void);
void when(void);
void sendtofile(void);
void realgussing(void);

int main()
{

	when();
	struct info player[7] = { { 0 } };
	int y, x, num,rounds;
	printf("\n\n");
	system("color 4E"); //This changes the color to Red 
	printf("****************************************\n");
	printf("-------------LION GAME-------- ---------\n");
	printf("***********BY FARHAN DAHIR**************\n");
	printf("****************************************\n");
	printf("\nHow many playes are playing this game: ");
	scanf("%d", &num);
	printf("How many Rounds do you wanna play: ");
	scanf("%d",&rounds);
	printf("\n");
	system("color 04");
	printf("\n");
	for (y = 0; y <num; y++)
	{

		printf("#%d Enter your ID number for the game:", y + 1);
		scanf("%d", &player[y].ID);
		printf("#%d enter your nickname: ", y + 1);
		scanf("%s", &player[y].name);
		printf("\n");

	}
	printf("\n");

	int i=0;

	while (i < rounds)
	{
	printf("Round %d\n",i+1);
	printf("\n");
	game(player, num);
	call(player, num);
	sendtofile();
	printf("\n\n");
	i++;
	}

	realgussing();

	return 0;
}

void game(struct info* player, int num)
{
	int x;
	for (x = 0; x < num; x++)
	{
		system("color 1");
		printf("PlayerName: %s\tPlayerID: %d \n\n",
			player[x].name,
			player[x].ID);
	}
	system("color 04");
}

void call(struct info* player, int num)
{

	int rounds = 15;


		int i;
		srand((unsigned)time(NULL));
		do
		{
			for (i = 0; i < rounds; i++) {
				pause();
				printf("\n");
				printf("%d\t%d\t%d\t%d\n", rand() % 50, rand() % 10, rand() % 10, rand() % 10);


			}

		} while (i > 15);






}

void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	return;
}


void clearKeyboard(void)
{
	while (getchar() != '\n');

}


void when(void)
{
	time_t now;

	time(&now);
	printf("It's now %s", ctime(&now));
}


void sendtofile(void)
{
	printf("Type the winner's name into a file\n\n");

	int r, f;
	const char filename[] = "winner.csv";
	char data[30];

	printf("Enter the winners name:");
	scanf("%s", &data);
	printf("Enter Winner's points: ");
	scanf("%d", &f);
	FILE* fp = fopen(filename, "a");

	if (fp != NULL)
	{

		fprintf(fp, "%s  won this round with %d\n", data, f);

		fclose(fp);

		fp = NULL;
	}

	else
	{
		printf("The file couln't be opend:\n");
	}
	printf("\n");
	int m = 1;
	printf("WINNER of ROUND %d is %s\n", m, data);
	m++;
	pause();


}

/* I am still woring on
I will try to make a good game that LIONS can play on their free time*/
void realgussing(void)
{


	int random_num = 0;
	int guessed_num = 0;
	int counter = 0;

	srand(time(NULL));
	random_num = rand() % 10 + 1;

	printf("Guess my number! ");

	while (1)
	{
		counter++;

		scanf("%d", &guessed_num);

		if (guessed_num == random_num)
		{
			printf("You guessed correctly in %d tries! Congratulations!\n", counter);
			break;
		}

		if (guessed_num < random_num)
			printf("Your guess is too low. Guess again. ");

		if (guessed_num > random_num)
			printf("Your guess is too high. Guess again. ");

	}




}
