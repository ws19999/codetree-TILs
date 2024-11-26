fun main()
{
    val str=readLine()!!
    val keys:MutableMap<Char,Char>
    val s=readLine()!!
    var c='a'
    for(i in s)
    {
        keys[i]=c
        c++
    }
    for(i in str)
    {
        if(i!=' ')print("${keys[i]}")
        else print(" ")
    }
}