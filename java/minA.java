package okay;
public class minA {
public static void main(String args[]){
	int arr[]={2,4,3,6,1,7,3};
	int min=arr[0];
	for(int i=0;i<arr.length;i++){
		if(min > arr[i])
			min=arr[i];
	}
	System.out.println("Smallest no in list is "+min);
}
}
