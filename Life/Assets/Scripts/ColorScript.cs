using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColorScript : MonoBehaviour
{
    public Material red;
    public Material green;
    public bool isLife;
    // Start is called before the first frame update
    void Start()
    {
        isLife = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (this.transform.position.y < 20f)
        {
            gameObject.GetComponent<MeshRenderer>().material = red;
            isLife = false;
        }
        else
        {
            gameObject.GetComponent<MeshRenderer>().material = green;
            isLife = true;
        }
    }

    private void OnMouseUp()
    {
        if (GameObject.Find("Main Camera").GetComponent<Brains>().isStart == true)
            return;
        int x = 0, y = 0;
        // Debug.Log(GameObject.Find("Main Camera"));
        GameObject.Find("Main Camera").GetComponent<Brains>().getCubeCoord(gameObject, ref x, ref y);
        if (this.isLife == true)
        {
            this.isLife = false;
            GameObject.Find("Main Camera").GetComponent<Brains>().curGeneration[x, y] = false;
            this.GetComponent<moveUp>().enabled = false;
            this.GetComponent<moveDown>().enabled = true;
        }
        else
        {
            this.isLife = true;
            GameObject.Find("Main Camera").GetComponent<Brains>().curGeneration[x, y] = true;
            this.GetComponent<moveDown>().enabled = false;
            this.GetComponent<moveUp>().enabled = true;
        }
    }



    public void liven()
    {
        this.isLife = true;
        this.GetComponent<moveDown>().enabled = false;
        this.GetComponent<moveUp>().enabled = true;
    }



    public void kill()
    {
        this.isLife = false;
        this.GetComponent<moveUp>().enabled = false;
        this.GetComponent<moveDown>().enabled = true;
    }

}
