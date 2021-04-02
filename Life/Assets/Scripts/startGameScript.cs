using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class startGameScript : MonoBehaviour
{
    public Material red;
    public Material green;


    // Start is called before the first frame update
    void Start()
    {
        gameObject.GetComponent<MeshRenderer>().material = green;
    }



    private void OnMouseUp()
    {
        if (GameObject.Find("Main Camera").GetComponent<Brains>().isStart == false)
        {
            gameObject.GetComponent<MeshRenderer>().material = red;
            GameObject.Find("Main Camera").GetComponent<Brains>().count = 1;
            GameObject.Find("Main Camera").GetComponent<Brains>().isStart = true;
        }
        else
        {
            gameObject.GetComponent<MeshRenderer>().material = green;
            GameObject.Find("Main Camera").GetComponent<Brains>().isStart = false;
            GameObject.Find("Main Camera").GetComponent<Brains>().killAll();
            GameObject.Find("Main Camera").GetComponent<Brains>().zeros();
        }
    }



    public void setGreen()
    {
        gameObject.GetComponent<MeshRenderer>().material = green;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
