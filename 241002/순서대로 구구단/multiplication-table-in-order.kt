fun main()
{
    val (a,b)=readLine()!!.split(" ").map{it.toInt()}
    for(i in 1..9)
    {
        if(a>b)
        {
            for(j in a downTo b)
            {
                print("${j} * ${i} = ${j*i}  ")
            }
            print("\n")
        }
        else
        {
            for(j in a..b)
            {
                print("${j} * ${i} = ${j*i}  ")
            }
            print("\n")
        }
    }
    
}