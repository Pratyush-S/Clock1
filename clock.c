 /////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : clock
//
//  Target Board : atmega32
//
//  Date Created : 28-01-2018 22:45:28
// 
//  Online Resource  : www.electronicsforstudents.com
//
//  Libraries Included : -->wifi 
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<avr/io.h>
#include<util/delay.h>


#include "serial.h"
#include "lcd.h"


int main()
{ lcd_init();
	lcd_clear();
	lcd_string("Programm initz");
	
	serial_init(9600);
		serial_select(2);  //2 for wifi, 3 for gps

	wifi_init();
		int a=wifi_connect(PSTR("pratyush"),PSTR("poolloop"));
		lcd_clear();
		if(a=0)lcd_string("No wifi");
		if(a=1)lcd_string("Connected");

char response[40],key[40],time[15],date[15];

//wifi_http_get("http://api.timezonedb.com/v2/get-time-zone?key=D70CN5FUSM98&format=json&fields=formatted&by=zone&zone=Asia/Kolkata",json);
lcd_clear();
lcd_string("Here");
//wifi_http_get("api.clobous.com/E64744/button/retrieve?key1",response);	//here we are retreiving the btn1 value in the response variable 


wifi_http_get("api.clobous.com/E64744/data/update?key1=test");	
	
	
	lcd_clear();
lcd_string("NOW");
	
	//jsonparser for btn 1 starts here
	
	//jsonparser(response,"key1",result_btn1);		//the response is char type so we are asking a particular value of a key, so in order to eract that value jsonparser is used
	
	lcd_gotoxy(0,1);
	lcd_string(response);	//for displaying the result
	
	



	while (1)
	{	}

}