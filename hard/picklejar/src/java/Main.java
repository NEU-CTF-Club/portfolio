import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Scanner;
import java.io.InputStream;

public class Main {
  private static native boolean checkFlag(String flag);

  public static void main(String[] args) throws IOException {
    System.out.println("tell me what the flag is and i'll give you a cat!");

    Scanner scanner = new Scanner(System.in);
    String flag = scanner.nextLine();
    scanner.close();

    InputStream is = Main.class.getResourceAsStream("/lib/libpickles.so");
    File file = File.createTempFile("lib", ".so");
    OutputStream os = new FileOutputStream(file);
    byte[] buffer = new byte[1024];
    int length;
    while ((length = is.read(buffer)) != -1) {
      os.write(buffer, 0, length);
    }
    is.close();
    os.close();

    System.load(file.getAbsolutePath());
    file.deleteOnExit();


    boolean correct = checkFlag(flag);

    if (correct) {
      System.out.println("this cat is happy with your flag! :D");
      System.out.println("  ／l、             \n" +
              "（ﾟ､ ｡ ７ meow    \n" +
              "   l  ~ヽ       \n" +
              "  じしf_,)ノ");
    } else {
      System.out.println("that's not it! scram! >:(");
    }
  }
}