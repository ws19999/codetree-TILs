fun main()
{
    val str=readLine()!!
    val len=str.length
    var ee=false
    var ea=false
    for(i in 0..len-2)
    {
        if(str[i]=='e')
        {
            if(str[i+1]=='e')ee=true
            if(str[i+1]=='a')ea=true
        }
    }
    if(ee==true)print("YES ")
    else print("NO ")
    if(ea==true)print("YES")
    else print("NO")
}