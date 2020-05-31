#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<string>
#include<iomanip>

int main(){
	int row=0;                               // declare array's row
	int column=0;            	             //declare array's column;
	int y=0,x=0;                            // fire's location
	cin>>row>>column;
	cin>>x>>y;

	char matrix[row][column]={'0'};             // a matrix for map
	string arr;
	for(int i=0;i<row;i++){                     // can be adjust to char input row*col times
		cin>>arr;
		for(int j=0;j<column;j++){
            matrix[i][j]=arr[j];
		}

	}
//for question1==================================================================
    cout<<"[1]show the map:\n";
	int test_count=0;
	for(int i=0;i<row*column;i++){
        if(i!=0 && i%column==0){
            test_count++;
            cout<<endl;                                            // to check it is '%' or '+' or '$' and output it's correspondence value
        }
        if(matrix[test_count][i%column]=='%'){
            cout<<setw(2)<<"-1";
        }
        else if(matrix[test_count][i%column]=='+'){
            cout<<setw(2)<<"1";
        }
        else if(matrix[test_count][i%column]=='$'){
            cout<<setw(2)<<"0";
        }
	}
	cout<<"\n===================================================="<<endl;
//for question 2===========================================================================
    int current=0, num=0;                                           // former for stack, later for section number
	int **matrix1=new int*[row];
    for (int i = 0; i < row; i++)
    matrix1[i] = new int[column];
    bool visit[row*column]={0};                                    // to record if pass or not
    int test_count1=0;
    for(int i=0;i<row;i++){                                         //initial the matrix
        for(int j=0;j<column;j++){
            matrix1[i][j]=0;
        }
    }

    for(int i=0;i<row*column;i++){                                  //to visit the each element in matrix

        if((!visit[i]) &&matrix[i/column][i%column]=='$'){           // if have not been visit and it char its $
            stack<int> s;                                                                                                                   // use DFS
            s.push(i);
            visit[i]=1;
            num++;                                                   // to increase it's section's number
            while(!s.empty()){
                current=s.top();
                s.pop();
                matrix1[current/column][current%column]=num;        // put section's number in matrix

                if((current/column-1>=0)? (matrix[(current/column)-1][current%column]=='$'||matrix[(current/column)-1][current%column]=='%')&&visit[current-column]==0:0){         //top
                    visit[current-column]=1;
                    s.push(current-column);
                }
                if(current/column+1<=(row*column)?(matrix[(current/column)+1][current%column]=='$'||matrix[(current/column)+1][current%column]=='%')&&visit[current+column]==0:0){         //down
                    visit[current+column]=1;
                    s.push(current+column);
                }
                 if((current%column)? (matrix[(current/column)][current%column-1]=='$'|| matrix[(current/column)][current%column-1]=='%')&&visit[current-1]==0:0){         //left
                    visit[current-1]=1;
                    s.push(current-1);
                }
                if((current%column!=column-1)? (matrix[(current/column)][current%column+1]=='$'|| matrix[(current/column)][current%column+1]=='%')&&visit[current+1]==0:0){         //right
                    visit[current+1]=1;
                    s.push(current+1);
                }
            }
        }
    }
    cout<<"[2]show the map:\n";
    int test_count2=0;
    for(int i=0;i<row*column;i++){
        if(i!=0 && i%column==0){
            test_count2++;
            cout<<endl;
        }
        cout<<setw(3)<<matrix1[test_count2][i%column];
    }
    cout<<"\nThe number of regions is? "<<num;
	cout<<"\n===================================================="<<endl;

// for question 3==================================================================================

    bool visit1[row*column]={0};
    int *matrix2=new int[row*column];
    for(int i=0;i<row*column;i++)
        matrix2[i]=0;
    int D[row*column]={0};
    int current1=0;
    for(int i=0;i<row*column;i++){
        if(matrix[i/column][i%column]=='%'){
            queue<int> q;                                                                                                                            // use BFS
            q.push(i);                                                                                                                                  // push unvisited to the queue
            visit1[i]=1;                                                                                                                               //set visited
            matrix2[i]=-1;                                                                                                                              // set the people's location
            while(!q.empty()){
                current1=q.front();
                q.pop();
                if((current1/column-1>=0)? matrix[(current1/column)-1][current1%column]=='$'&&visit1[current1-column]==0:0){         //top
                    visit1[current1-column]=1;
                    q.push(current1-column);
                    matrix2[current1-column]=D[current1]+1;
                    D[current1-column]=D[current1]+1;
                }
                if(current1/column+1<=(row*column)?matrix[(current1/column)+1][current1%column]=='$'&&visit1[current1+column]==0:0){         //down
                    visit1[current1+column]=1;
                    q.push(current1+column);
                    matrix2[current1+column]=D[current1]+1;
                    D[current1+column]=D[current1]+1;
                }
                if((current1%column)? matrix[(current1/column)][current1%column-1]=='$'&&visit1[current1-1]==0:0){         //left
                    visit1[current1-1]=1;
                    q.push(current1-1);
                    matrix2[current1-1]=D[current1]+1;
                    D[current1-1]=D[current1]+1;
                }
                if((current1%column!=column-1)?matrix[(current1/column)][current1%column+1]=='$'&&visit1[current1+1]==0:0){         //right
                    visit1[current1+1]=1;
                    q.push(current1+1);
                    matrix2[current1+1]=D[current1]+1;
                    D[current1+1]=D[current1]+1;
                }

            }

        }

    }
    cout<<"[3]show the map:\n";
    int test_count3=0;
    for(int i=0;i<row*column;i++){
        if(i!=0 && test_count3==column){
            test_count3=0;
            cout<<endl;
        }
        test_count3++;
        cout<<setw(3)<<matrix2[i];
    }
    int min_step=row*column;
    for(int i=0;i<row*column;i++){
        if(i%column==0 || i%column==column-1 || i/column==0 || i/column==row-1){
            if(matrix2[i]<min_step && matrix2[i]!=0){
                min_step=matrix2[i];
            }
        }
    }
    if(min_step==row*column){
        min_step=-1;
    }
    cout<<"\nIs there a minimum path? "<<min_step;
	cout<<"\n===================================================="<<endl;
// for question 4 bonus==================================================================================
    bool visit4[row*column]={0};
    int *firemap=new int[row*column];
    for(int i=0;i<row*column;i++)
        firemap[i]=0;
    int D4[row*column]={0};
    int current4=0;
    for(int i=0;i<row*column;i++){
        if(i==column*x+y){
            queue<int> q4;                                                                                      //use BFS
            q4.push(i);                                                                                         // push unvisited to the queue
            visit4[i]=1;                                                                                        // set visited
            firemap[i]=-1;                                                                                      // to record the fire location on the map
            while(!q4.empty()){
                current4=q4.front();
                q4.pop();
                if((current4/column-1>=0)? (matrix[(current4/column)-1][current4%column]=='$'||matrix[(current4/column)-1][current4%column]=='%')&&visit4[current4-column]==0:0){         //top
                    visit4[current4-column]=1;
                    q4.push(current4-column);
                    firemap[current4-column]=D4[current4]+1;
                    D4[current4-column]=D4[current4]+1;
                }
                if(current4/column+1<=(row*column)?(matrix[(current4/column)+1][current4%column]=='$'||matrix[(current4/column)+1][current4%column]=='%')&&visit4[current4+column]==0:0){         //down
                    visit4[current4+column]=1;
                    q4.push(current4+column);
                    firemap[current4+column]=D4[current4]+1;
                    D4[current4+column]=D4[current4]+1;
                }
                if((current4%column)? (matrix[(current4/column)][current4%column-1]=='$'||matrix[(current4/column)][current4%column-1]=='%')&&visit4[current4-1]==0:0){         //left
                    visit4[current4-1]=1;
                    q4.push(current4-1);
                    firemap[current4-1]=D4[current4]+1;
                    D4[current4-1]=D4[current4]+1;
                }
                if((current4%column!=column-1)?(matrix[(current4/column)][current4%column+1]=='$'||matrix[(current4/column)][current4%column+1]=='%')&&visit4[current4+1]==0:0){         //right
                    visit4[current4+1]=1;
                    q4.push(current4+1);
                    firemap[current4+1]=D4[current4]+1;
                    D4[current4+1]=D4[current4]+1;
                }
                if((current4/column-1>=0 && current4%column!=0)? (matrix[(current4/column)-1][current4%column-1]=='$'||matrix[(current4/column)-1][current4%column-1]=='%')&&visit4[current4-column-1]==0:0){         // upper left
                    visit4[current4-column-1]=1;
                    q4.push(current4-column-1);
                    firemap[current4-column-1]=D4[current4]+1;
                    D4[current4-column-1]=D4[current4]+1;
                }
                if((current4/column-1>=0 && current4%column!=column-1)?(matrix[(current4/column)-1][current4%column+1]=='$'||matrix[(current4/column)-1][current4%column+1]=='%')&&visit4[current4-column+1]==0:0){         //upper right
                    visit4[current4-column+1]=1;
                    q4.push(current4-column+1);
                    firemap[current4-column+1]=D4[current4]+1;
                    D4[current4-column+1]=D4[current4]+1;
                }
                if(current4/column+1<=(row*column) &&current4%column!=0 ? (matrix[(current4/column+1)][current4%column-1]=='$'||matrix[(current4/column+1)][current4%column-1]=='%')&&visit4[current4+column-1]==0:0){         //lower left
                    visit4[current4+column-1]=1;
                    q4.push(current4+column-1);
                    firemap[current4+column-1]=D4[current4]+1;
                    D4[current4+column-1]=D4[current4]+1;
                }
                if(current4/column+1<=(row*column) &&current4%column!=column-1 ? (matrix[(current4/column+1)][current4%column+1]=='$'||matrix[(current4/column+1)][current4%column+1]=='%')&&visit4[current4+column+1]==0:0){         //lower right
                    visit4[current4+column+1]=1;
                    q4.push(current4+column+1);
                    firemap[current4+column+1]=D4[current4]+1;
                    D4[current4+column+1]=D4[current4]+1;
                }

            }

        }

    }
    cout<<"[4]show the map:\n";
    int test_count4=0;
    for(int i=0;i<row*column;i++){
        if(i!=0 && test_count4==column){
            test_count4=0;
            cout<<endl;
        }
        test_count4++;
        cout<<setw(3)<<firemap[i];
    }
    int min_step1=row*column;
    for(int i=0;i<row*column;i++){
        if(i%column==0 || i%column==column-1 || i/column==0 || i/column==row-1){
            if(matrix2[i]<min_step1 && matrix2[i]!=0 &&(firemap[i]>matrix2[i])){                           //matrix2[i]!=0 &&(firemap[i]>matrix2[i])   *to compare question3 result and firemap*
                min_step1=matrix2[i];
            }
        }
    }
    if(min_step1==row*column){
        min_step1=-1;
    }
    cout<<"\nCan they escape from the fire? "<<min_step1<<endl;
	system("pause");






	return 0;

}



