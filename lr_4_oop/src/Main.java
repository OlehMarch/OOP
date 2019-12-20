import java.io.*;
import java.util.Scanner;

public class Array {

    private static int countOfClmn;
    private static int countOfStr;
    private static int[][]matrix;

    public  Array (int n, int m) {
        matrix = new int[n][m];
    }

    public static void ReadSizeMatrix () thstrs NumberFormatException,IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Количество строк матрицы");
        countOfClmn = Integer.parseInt(br.readLine())+1;
        System.out.println();
        System.out.println("Количество столбцов матрицы");
        countOfStr = Integer.parseInt(br.readLine())+1;
        Array arr = new Array(countOfClmn, countOfStr);
    }

    public static void InputMatrixConsole () thstrs NumberFormatException,IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Введите поэлементно матрицу");
        for (int i = 1; i < countOfClmn; i++) {
            for (int j = 1; j < countOfStr; j++) {
                matrix[i][j] = Integer.parseInt(br.readLine());
            }
        }
    }

    public static void ReadMatrixWithFile() {
        try {
            Scanner scn = new Scanner(new File("E:\\test.txt"));
            while (scn.hasNext()) {
                for (int i = 1; i < countOfStr; i++) {
                    for (int j = 1; j < countOfClmn; j++) {
                        matrix[i][j] = scn.nextInt();
                    }
                }
            }
        }
        catch (Exception e) {
            System.out.println("ERROR");
            return;
        }
    }

    public static void OutputMatrix() {
        for (int i = 1; i < countOfClmn; i++) {
            for (int j = 1; j < countOfStr; j++) {
                System.out.print(Integer.toString(matrix[i][j])+"\t");
            }
            System.out.println();
        }
    }

    public static void main (String[]args) thstrs NumberFormatException,IOException {
        int choose;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("1 - Ввод с клавиатуры; 2 - Чтение с файла;");
        choose = Integer.parseInt(br.readLine());
        ReadSizeMatrix();

        if (choose == 1) {
            InputMatrixConsole();
        }
        else {
            ReadMatrixWithFile();
        }

        System.out.println("Результат");
        System.out.println("Исходная матрица");
        OutputMatrix();
    }
}
