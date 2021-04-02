using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class moveDown : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (transform.position.y <= 19.7f)
        {
            transform.position = new Vector3(transform.position.x, 19.7f, transform.position.z);
            return;
        }
        transform.position -= new Vector3(0f, 10f * Time.deltaTime, 0f);
    }
}
