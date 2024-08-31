fun main()
{
    val (a,b) = readLine()!!.split(" ").map{it.toInt()}
    if(a>b)
    {
        for(i in a downTo b)
        {
            for(j in 0..2)
            {
                for(k in 1..3)
                {
                    print("${i} * ${k+j*3} = ${i*(k+j*3)}  ")
                }
                print("\n")
            }
            print("\n")
        }
    }
    else
    {
        for(i in a..b)
        {
            for(j in 0..2)
            {
                for(k in 1..3)
                {
                    print("${i} * ${k+j*3} = ${i*(k+j*3)}  ")
                }
                print("\n")
            }
            print("\n")
        }
    }
}