using System.Collections;
using System.Collections.Generic;
using System.Threading;
using UnityEngine;

public class Brains : MonoBehaviour
{
    public bool[,] prevGeneration = new bool[22, 22]; // +2 - phantom cells
    public bool[,] curGeneration = new bool[22, 22]; // +2 - phantom cells
    public GameObject cube;
    public GameObject timer;
    public GameObject[,] cubes = new GameObject[22, 22];
    public bool isStart = false;
    float timerF = 0f;
    public GameObject counter;
    public int count = 1;
    // Start is called before the first frame update
    void Start()
    {
        isStart = false;
        //generation of cubes
        float   x = -23.7f,
                y = 19.7f,
                z = -23.7f;

        for (int i = 1; i < 21; i++)
            for (int j = 1; j < 21; j++)
            {
                cubes[i, j] = Instantiate(cube, new Vector3(x + ((j - 1f) * 2.5f), y, z + ((i - 1f) * 2.5f)), new Quaternion(0f, 0f, 0f, 0f));
                //cubes[i, j].transform.position = new Vector3(x + ((j - 1f) * 2.5f), y, z + ((i - 1f) * 2.5f));
                cubes[i, j].name = "Cube" + i + "_" + j;
            }
        zeros();
    }



    public void zeros()
    {
        // zeros
        for (int i = 0; i < 22; i++)
            for (int j = 0; j < 22; j++)
            {
                prevGeneration[i, j] = false;
                curGeneration[i, j] = false;
            }
    }



    bool isLife()
    {
        for (int i = 1; i < 21; i++)
            for (int j = 1; j < 21; j++)
            {
                if (curGeneration[i, j] == true && !isCycle())
                    return true;
            }
        zeros();
        return false;
    }



    bool isCycle()
    {
        for (int i = 1; i < 21; i++)
            for (int j = 1; j < 21; j++)
            {
                if (curGeneration[i, j] != prevGeneration[i, j])
                    return false;
            }
        return true;
    }



    public void killAll()
    {
        for (int i = 1; i < 21; i++)
            for (int j = 1; j < 21; j++)
            {
                cubes[i, j].GetComponent<ColorScript>().kill();
            }
    }



    public void getCubeCoord(GameObject cube, ref int x, ref int y)
    {

        for (int i = 1; i < 21; i++)
            for (int j = 1; j < 21; j++)
            {
                if (cubes[i, j] == cube)
                {
                    x = i;
                    y = j;
                    return;
                }
            }
        return;
    }



    void copyGeneration()
    {
        for (int i = 1; i < 21; i++)
            for (int j = 1; j < 21; j++)
                prevGeneration[i, j] = curGeneration[i, j];     
    }



    int getCountOfLivingCells(int x, int y) // x, y - coords on grid
    {
        int _out = 0;
        for (int i = x - 1; i < x + 2; i++)
        {
            for (int j = y - 1; j < y + 2; j++)
            {
                if (i == x && j == y)
                    continue;
                if (prevGeneration[i, j] == true)
                {
                    _out++;
                }
            }
        }
        return _out;
    }



    void getNextGeneration()
    {
        copyGeneration();
        for (int i = 1; i < 21; i++)
        {
            for (int j = 1; j < 21; j++)
            {
                int countOfLivingCells = getCountOfLivingCells(i, j);
                if (prevGeneration[i, j] == false && countOfLivingCells == 3)
                {
                    curGeneration[i, j] = true;
                }
                else if (prevGeneration[i, j] == true && 
                    (countOfLivingCells < 2 || countOfLivingCells > 3))
                {
                    curGeneration[i, j] = false;
                }
            }
        }
    }



    private void draw()
    {
        for (int i = 1; i < 21; i++)
            for (int j = 1; j < 21; j++)
            {
                if (curGeneration[i, j] == prevGeneration[i, j])
                    continue;
                if (curGeneration[i, j] == false)
                    cubes[i, j].GetComponent<ColorScript>().kill();
                else if(curGeneration[i, j] == true)
                    cubes[i, j].GetComponent<ColorScript>().liven();
            }
    }


    // Update is called once per frame
    void Update()
    {
        if (isStart != false)
        {
            gameObject.transform.position = Vector3.Lerp(transform.position, new Vector3(0f, 70f, -50f), 1 * Time.deltaTime);
            gameObject.transform.rotation = Quaternion.Lerp(transform.rotation, Quaternion.Euler(50f, 0f, 0f), 1 * Time.deltaTime);
            if (timer.GetComponent<timerScript>().timer - timerF > 0.5f)
            {
                counter.GetComponent<TextMesh>().text = count++.ToString();
                getNextGeneration();
                draw();
                timerF = timer.GetComponent<timerScript>().timer;

                if (!isLife())
                {
                    isStart = false;
                    killAll();
                    GameObject.Find("startButton").GetComponent<startGameScript>().setGreen();
                }
            }
        }
        else
        {
            gameObject.transform.position = Vector3.Lerp(transform.position, new Vector3(0f, 80f, -25f), 1 * Time.deltaTime);
            gameObject.transform.rotation = Quaternion.Lerp(transform.rotation, Quaternion.Euler(70f, 0f, 0f), 1 * Time.deltaTime);
        }
    }
}




                //string log = "";
                //for (int i = 1; i < 21; i++)
                //{
                //    for (int j = 1; j < 21; j++)
                //    {
                //        if (curGeneration[i, j])
                //            log += "1 ";
                //        else
                //            log += "0 ";
                //    }
                //    Debug.Log(log);
                //    log = "";
                //}
                //Debug.Log("=================================");
                //Debug.Log("                                 ");