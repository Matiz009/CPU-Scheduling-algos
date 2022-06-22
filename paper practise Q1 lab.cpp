#include<stdio.h>
#include<string.h> 

int main() {
	
	int i = 0, j, n, check = 0, temp_r, temp_l, temp_m;
	char temp_g[15];
	
	printf("enter the number of movies stored in the database: ");
	scanf("%d", &n);
	
	int m[n];
	int r[n];
	int l[n];
	char g[n][15]; 
	char g_type[3][15] = {"classic", "action", "drama"}; 
	
	for(i = 0; i < n; i++) {
		printf("enter the movie number: ");
	    scanf("%d", &m[i]);
	    
	    do {
	    	printf("enter the movie rating: ");
	        scanf("%d", &r[i]);
		}while(!(r[i] >= 1 && r[i] <= 5));
		
		do {
	    	printf("enter the movie length: ");
	        scanf("%d", &l[i]);
		}while(!(l[i] >= 30 && l[i] <= 200));
	    
	    do {
	    	printf("enter the movie genre: ");
	        scanf("%s", &g[i][0]);
	        
	        for(j = 0; j < 3; j++) {
	        	if(strcmp(g[i], g_type[j]) == 0) {
	        		check = 1;
	        		break;
				} 
			}
		}while(check != 1);
		check = 0;
		
	}
	
	printf("\n2-----\nMovie \t|Rating \t|Length \t|Genre");
	for(i = 0; i < n; i++){
		printf("\n%d \t|%d \t\t|%d \t\t|%s", m[i], r[i], l[i], g[i]);
	}
	
	/**
Question:02
Assume that you are the main developer of a famous Satellite Television company that plays movies to its subscribed users
(but not on demand). You are supposed to write their software to implement the following criteria:

1) The movies are stored in the database with its rating, length, and genre.
2) The rating should be a number from 1 to 5. The length should be from 30 to 200 minutes.
The genre should be classic, action, or drama. You must place checks to keep things in these limits.
3) The movie having the highest rating will be played first.
4) If the rating of two movies is same, the one having longer length will be played first.
5) If the length of two movies is same, the one having action genre will be played first.
*/
for(i = 0; i < n; i++) {
	for(j = 0; j < n-1; j++) {
		if(r[j] < r[j+1]) {
			temp_m = m[j];
			temp_r = r[j];
			temp_l = l[j];
			strcpy(temp_g,g[j]);
			
			m[j] = m[j+1];
			r[j] = r[j+1];
			l[j] = l[j+1];
			strcpy(g[j], g[j+1]);
			
			m[j+1] = temp_m;
			r[j+1] = temp_r;
			l[j+1] = temp_l;
			strcpy(g[j+1], temp_g);
		}
	}
}

	printf("\n3-----\nMovie \t|Rating \t|Length \t|Genre");
	for(i = 0; i < n; i++){
		printf("\n%d \t|%d \t\t|%d \t\t|%s", m[i], r[i], l[i], g[i]);
	}
	
for(i = 0; i < n; i++) {
	for(j = 0; j < n-1; j++) {
		if(r[j] == r[j+1] && l[j] < l[j+1]) {
			temp_m = m[j];
			temp_r = r[j];
			temp_l = l[j];
			strcpy(temp_g,g[j]);
			
			m[j] = m[j+1];
			r[j] = r[j+1];
			l[j] = l[j+1];
			strcpy(g[j], g[j+1]);
			
			m[j+1] = temp_m;
			r[j+1] = temp_r;
			l[j+1] = temp_l;
			strcpy(g[j+1], temp_g);
		}
	}
}

	printf("\n4-----\nMovie \t|Rating \t|Length \t|Genre");
	for(i = 0; i < n; i++){
		printf("\n%d \t|%d \t\t|%d \t\t|%s", m[i], r[i], l[i], g[i]);
	}
	
		
for(i = 0; i < n; i++) {
	for(j = 0; j < n-1; j++) {
		if(l[j] == l[j+1] && strcmp(g[j+1], "action") == 0) {
			temp_m = m[j];
			temp_r = r[j];
			temp_l = l[j];
			strcpy(temp_g,g[j]);
			
			m[j] = m[j+1];
			r[j] = r[j+1];
			l[j] = l[j+1];
			strcpy(g[j], g[j+1]);
			
			m[j+1] = temp_m;
			r[j+1] = temp_r;
			l[j+1] = temp_l;
			strcpy(g[j+1], temp_g);
		}
	}
}
	printf("\n\n5-----\nMovie \t|Rating \t|Length \t|Genre");
	for(i = 0; i < n; i++){
		printf("\n%d \t|%d \t\t|%d \t\t|%s", m[i], r[i], l[i], g[i]);
	}

}
