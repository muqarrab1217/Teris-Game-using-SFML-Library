//Muqarrab Ahmed  22i-1351  CS_D  FINAL PROJECT

/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//    
void fallingPiece(float& timer, float& delay, int& colorNum, int& delta_x){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;            //How much units downward
        }
        if (!anamoly()){
            for (int i=0;i<4;i++){
        	gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;
            }
            colorNum=1+rand()%7;
            int n=rand()%7;
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                }
        }
        timer=0;
        delay=0.3;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
void deleteRow(bool &flag){
int temp[M][N];
flag=false;
for(int i=19 ; i>0 ; i--){
    for(int j=0 ; j<N ; j++){
	if(gameGrid[i][j]==false){
		flag=false;
	break;
	}
	else if(j==9){
	flag=true;
	}
        else if(gameGrid[i][j]==true)
        flag=true;
    }
	for(int j=0 ; j<N ; j++){
		if(flag==true){
		   temp[i][j]=gameGrid[i][j];
		    gameGrid[i][j]=gameGrid[i-1][j];
		    gameGrid[i-1][j]=temp[i][j]; 
		}
	}
}
for(int i=0 ; i<2 ; i++){
    for(int j=0 ; j<N ; j++){
    gameGrid[i][j]=0;
    }
}
}

void moveRowDownwards(){
}

void rotateBlock(bool &rotate){
if(rotate){
int p = point_1[1][1];
for(int i=0 ; i<4 ; i++){
int y = point_1[i][0]-point_1[1][0];
int x = point_1[i][1]-point_1[1][1];
point_1[i][1] = point_1[1][1]+y;
point_1[i][0] = point_1[1][0]-x;
}
  if(!anamoly()){
    for(int i=0 ; i<4 ; i++){	
        point_1[i][1]=point_2[i][1];    
	point_1[i][0]=point_2[i][0];
	
    }
  }
}
rotate=0;
}

void moveLeft(int &delta_x){
	for(int i=0 ; i<4 ; i++){
		
            for(int i=0 ; i<4 ; i++){
            point_1[i][0]+=delta_x;
            }
            delta_x=0;
            if(point_1[i][0]<0){
        		for(int i=0 ; i<4 ; i++){
			point_1[i][0]+=1;
			}
	    }
	    }
}

void moveRight(int &delta_x){
	for(int i=0 ; i<4 ; i++){	
        
            	for(int i=0 ; i<4 ; i++){
            	point_1[i][0]+=delta_x;
            	}
            	delta_x=0;
            	if(point_1[i][0]>N-1){
			for(int i=0 ; i<4 ; i++){
			point_1[i][0]-=1;			
			}
		}
		}
}

void instantFall(){
	//if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=10;              //How much units downward
        }
	 //}
}
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
