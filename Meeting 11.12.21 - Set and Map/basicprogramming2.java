import java.util.*;
import java.io.*;

class basicprogramming2{
    public static ArrayList<Integer> arr;
    public static FastScanner sc;
    public static int n, t;

    public static void main(String[] args){
        sc = new FastScanner();
        n = sc.nextInt();
        t = sc.nextInt();
        arr = new ArrayList<>();
        for(int i = 0; i < n; i++){
            arr.add(sc.nextInt());
        }
        switch (t) {
            case 1: 
                twoSum(7777);
                break;
            case 2:
                unique();
                break;
            case 3: 
                findMode(n/2);
                break;
            case 4: 
                findMedian();
                break;
            case 5: 
                printRange(100, 999);
                break;
        }
    }


    private static void printRange(int min, int max) {
        Collections.sort(arr);
        StringBuilder sb = new StringBuilder();
        for(int val : arr){
            if(val < min) continue;
            if(val > max) break;
            sb.append(val).append(' ');
        }
        System.out.println(sb);
    }


    private static void findMedian() {
        Collections.sort(arr);
        if(n%2 == 1){
            System.out.println(arr.get(n/2));
            return;
        }
        System.out.println(arr.get(n/2 - 1) + " " + arr.get(n/2));
    }

    private static void findMode(int targetQuantity) {
        int num = -1;
        TreeMap<Integer, Integer> m = new TreeMap<>();
        for(int i : arr){
            if(m.containsKey(i)){
                m.replace(i, m.get(i)+1);
            } else {
                m.put(i, 1);
            }
        }
        for(Map.Entry<Integer, Integer> entry : m.entrySet()){
            int val = entry.getValue();
            if(val > targetQuantity){
                num = entry.getKey();
            }
        }
        System.out.println(num);
    }

    private static void unique() {
        TreeSet<Integer> s = new TreeSet<>();
        for(int i : arr) {
            if(!s.add(i)) {
                System.out.println("Contains duplicate");
                return;
            }
            // s.add(i);
        }
        System.out.println("Unique");
    }

    private static void twoSum(int target) {
        TreeSet<Integer> s = new TreeSet<>();
        for(int i : arr) {
            if(s.contains(target - i)){
                System.out.println("Yes");
                return;
            }
            s.add(i);
        }
        System.out.println("No");
    }

    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            try {
                return br.readLine();
            } catch(IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}