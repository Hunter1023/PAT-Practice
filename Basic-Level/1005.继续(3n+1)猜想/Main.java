import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cnt = in.nextInt();
		KeyNum keynum = new KeyNum(cnt);
		
		for(int i = 0; i < cnt; i++) {
			keynum.setNum(i,in.nextInt());
		}
		keynum.rankNum();
		keynum.getKeyNum();
		keynum.outPut();
	}
}

class KeyNum {
	private int[] arr;
	private int cnt;
	public KeyNum(int cnt) {
		arr = new int[cnt];
		this.cnt = cnt;
	}
	
	public void setNum(int index, int figure) {
			arr[index] = figure;
	}
	
	public void rankNum() {
		for(int x = 0; x < arr.length; x++) {
			for(int y = 0; y < arr.length-x-1; y++) {
				if(arr[y] < arr[y+1]) {
					int temp = arr[y];
					arr[y] = arr[y+1];
					arr[y+1] = temp;
				}
			}
		}
	}
	
	public void getKeyNum() {
		for(int i = 0; i < arr.length; i++) {
			int updateNum = arr[i];
			
			while(updateNum != 1) {
				if(updateNum % 2 == 0){
					updateNum /= 2;
					for(int j = 0; j < arr.length; j++) {
						if(arr[j] == updateNum) {
							arr[j] = 1;
						}
					}
				}
				else{
					updateNum = (3*updateNum + 1) / 2;
					for(int j = 0; j < arr.length; j++) {
						if(arr[j] == updateNum) {
							arr[j] = 1;
						}
					}
				}
			}
		}
	}
	
	public void outPut() {
		String outPut ="";
		for(int i =0; i < arr.length; i++) {
			if(arr[i] != 1) {
				outPut += arr[i]+" ";
			}
		}
		outPut = outPut.trim();
		System.out.println(outPut);
	}
}
