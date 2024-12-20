import kotlin.math.sqrt
fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val num=readLine()!!.toInt()
    if(num==1)print("one")
    else {
        var prime = true
        for (i in 2..sqrt(num.toDouble()).toInt()) {
            if (num % i == 0) {
                prime = false
                break
            }
        }
        when (prime) {
            true -> print("prime")
            else -> print("composition")
        }
    }
    bw.close()
}