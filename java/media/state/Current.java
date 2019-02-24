package state;

public class Current {
  Integer state;
  Boolean running;

  public Current(Integer state){
    this.state = state;
    this.running = true;
  }

  public Integer getState(){
    return this.state;
  }

  public Boolean getRunning(){
    return this.running;
  }

  public void setState(Integer state){
    this.state = state;
  }

  public void stop(){
    this.running = false;
  }
}
