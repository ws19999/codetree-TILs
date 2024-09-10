fun main()
{
    val n=readLine()!!.toInt()
    for(i in 1..n)
    {
        val num=readLine()!!.toInt()
        if(num<0)println("minus")
        else if(num>0)println("plus")
        else println("zero")
    }
}