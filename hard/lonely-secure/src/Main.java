import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Base64;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;


public class Main {
  private static final String PASSWORD = "fiNRXxvfWQRLIYvBNCz0b1HzFRcoqsi9";

  public static void main(String[] args) {
    System.out.println("i'm so lonely at the bottom of the ocean, i need someone to talk to");
    long unixMillis = System.currentTimeMillis();
    String signString = String.format("%d", unixMillis);
    try {
      URL url = new URL("https://devin.dog/ctf/securedeepblue.php?timestamp=" + signString);

      HttpURLConnection con = (HttpURLConnection) url.openConnection();
      con.setRequestMethod("GET");
      con.setRequestProperty("X-Autograph", sign(signString));
      con.setRequestProperty("User-Agent", "NEU-CTFApp/1.0");

      BufferedReader in = new BufferedReader(
              new InputStreamReader(con.getInputStream()));
      String inputLine;
      StringBuffer content = new StringBuffer();

      while ((inputLine = in.readLine()) != null) {
        content.append(inputLine);
      }

      in.close();
      con.disconnect();

      if (content.toString().contains("CTF{")) {
        System.out.println("someone replied! they told me " + content);
      } else {
        System.out.println("nobody wants to talk to me... >.<");
      }
    } catch (Exception e) {
      System.out.println("couldn't connect >.<");
      System.exit(1);
    }
  }

  public static String sign(String plaintext) {
    try {
      SecretKeySpec keySpec = new SecretKeySpec(PASSWORD.getBytes(), "AES");
      Cipher cipher = Cipher.getInstance("AES");
      cipher.init(Cipher.ENCRYPT_MODE, keySpec);
      byte[] encryptedBytes = cipher.doFinal(plaintext.getBytes());
      return Base64.getEncoder().encodeToString(encryptedBytes);
    } catch (Exception e) {
      System.exit(1);
    }

    return "";
  }

}