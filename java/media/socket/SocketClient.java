package socket;

import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class SocketClient{
  private BufferedReader bufferReader;
  private BufferedWriter bufferWriter;

  public SocketClient(Socket client) throws Exception{
    InputStream inStr = client.getInputStream();
    InputStreamReader inStrRead = new InputStreamReader(inStr);
    this.bufferReader = new BufferedReader(inStrRead);

    OutputStream outStre = client.getOutputStream();
    OutputStreamWriter outStrWrite = new OutputStreamWriter(outStre);
    this.bufferWriter = new BufferedWriter(outStrWrite);
  }

  public String recv() throws Exception{
      String message = this.bufferReader.readLine();
      return message;
  }
  public void send(String message) throws Exception{
      this.bufferWriter.write(message+"\n");
      this.bufferWriter.flush();
  }
}
