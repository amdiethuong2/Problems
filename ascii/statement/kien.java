import java.util.*;

class kien {
	static Scanner cin = new Scanner(System.in);
	
	public static void main(String argv[]) {
		int m = cin.nextInt();
		int n = cin.nextInt();
		int Sum=0, b=0;
		
		for (int i=0; i<m; i++) {
			String s = cin.nextLine();
			while (s.isEmpty()) s=cin.nextLine();
			for (int j=0; j<n; j++)
			if (s.charAt(j)=='.') Sum+=b;
			else { b=2-b; Sum+=1; }
		}
		
		System.out.println(Sum/2);
	}
}

