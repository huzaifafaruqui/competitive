/*Program Developed By oculto*/

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class Main {
   

	static int MOD=1000000007;
	
	
	

	

	
	
	
	public static void main(String[] args) {
   
		//Main k=new Main();
	
	
	
			//System.out.println(BigInteger.valueOf(2).modInverse(BigInteger.valueOf(MOD)));
		
		
   MyScanner in=new MyScanner();
   PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

   int[] A=new int[100005];
   
   
   
   int n,t,i,x;
   long m,num,mult,y,ans,den,tnum,g,tden;
   
   
   t=in.nextInt();
   while(t-->0){
	   n=in.nextInt();
	   x=in.nextInt();
	   m=in.nextLong();
	  
	   mult=1;
	   num=m-1;
	   ans=den=0;
	   for(i=0;i<n;i++)
	   {    y=in.nextLong();
	         y=y%MOD;
		   A[i]=(int)y;
	   }
	   for(i=x-1;i>=0;i--)
	   {
		     
		     y=(long)mult*A[i];
		     y=y%MOD;
		     ans+=y;
		     ans%=MOD;
	       
	       num++;
	       den++;
	       tden=BigInteger.valueOf(den).modInverse(BigInteger.valueOf(MOD)).longValue();
	      
		   tnum=num%MOD;
		   mult*=tnum;
		   mult%=MOD;
		   mult*=tden;
		   mult%=MOD;
		   
	   }
	   
	   
	   ans=ans%MOD;
	   
	   
	   
	   out.println(ans);
	   
	  
	   
   }
    out.close();
	}


}

class MyScanner {
    BufferedReader br;
    StringTokenizer st;

    public MyScanner() {
       br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine(){
        String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
    }

 }
 
