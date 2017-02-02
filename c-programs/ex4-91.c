
	for (i = 0; i < LIMIT; i++) {

		switch (c = getchar()) {

		case EOF:  goto end;

		case ' ' : cblank++; 
			   break;

		case '\t': ctabs++;  
			   break;

		case '*' : cstars++;  
 			   break;

	        default  : if (c >= 'a' && c <= 'z')
                            clower++;
                            break;
		}
	}
	end:
