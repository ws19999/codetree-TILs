fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    var (w,h)=br.readLine().split(" ").map{it.toInt()}
    w*=4
    h+=3
    bw.write("$w\n$h\n${w*h}")
    bw.close()
}