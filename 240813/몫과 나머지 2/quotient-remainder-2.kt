fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    var (x,y)=br.readLine().split(" ").map{it.toInt()}
    if(y>x)
    {
        var temp=y
        y=x
        x=temp
    }
    bw.write("${x/y}---${x%y}")
    bw.close()
    br.close()
}