using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Start : MonoBehaviour
{
    public void GameSceneCtrl()
    {
        SceneManager.LoadScene("Roll-a-ball"); // ���� ������ �̵�
        Debug.Log("Game Scene Go");
    }
}
