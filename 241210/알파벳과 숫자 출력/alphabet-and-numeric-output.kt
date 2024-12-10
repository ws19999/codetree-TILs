fun main()
{
    val N=readLine()!!.toInt()
    var c='A'
    var num=1
    for(i in N downTo 1)
    {
        for(j in 1..N)
        {
            print("$c ")
            c++
            if(c>'Z')c='A'
        }
        for(j in 1..N+1-i){
            print("$num ")
            num++
            if(num==10)num=1
        }
        println()
    }
}