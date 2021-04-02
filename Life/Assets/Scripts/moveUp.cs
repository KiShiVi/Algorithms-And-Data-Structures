using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class moveUp : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // transform.position = new Vector3(transform.position.x, -0.8f, transform.position.z);
    }

    // Update is called once per frame
    void Update()
    {
        if (transform.position.y >= 21.6f)
        {
            transform.position = new Vector3(transform.position.x, 21.6f, transform.position.z);
            return;
        }
        transform.position += new Vector3(0f, 10f * Time.deltaTime, 0f);
    }
}
