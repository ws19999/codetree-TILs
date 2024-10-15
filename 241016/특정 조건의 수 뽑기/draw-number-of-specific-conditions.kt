import kotlin.math.abs
fun main()
    {
        val n=readLine()!!.toInt()
        val numbers=readLine()!!.trim().split(" ").map{it.toInt()}.toIntArray()
        var a=-1
        var b=99999
        for(i in 0..n-1)
        {
            if(abs(100-a)>abs(100-numbers[i]) || (abs(100-a)==abs(100-numbers[i]) && numbers[i]<100))
            {
                a=numbers[i]
            }
            if(numbers[i]>100 && numbers[i]<b)b=numbers[i]
        }
        if(b==99999)b=-1
        print("${a} ${b}")
    }