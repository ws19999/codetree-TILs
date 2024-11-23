import kotlin.math.min
import kotlin.math.max
fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val (a,b)=br.readLine().split(" ")
    val c=a[0]
    val d=b[0]
    bw.write("${c.code*d.code} ${max(c.code,d.code)%min(c.code,d.code)}")
    bw.close()
}