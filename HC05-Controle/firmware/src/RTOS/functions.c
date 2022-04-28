/*
 * functions.c
 *
 * Created: 4/27/2022 5:00:57 PM
 *  Author: franc
 */ 

void data_convert(char dataArray[], int data){
	char D0 = data;
	dataArray[0] = D0;
	
	char D1 = data << 8;
	dataArray[1] = D1;
}