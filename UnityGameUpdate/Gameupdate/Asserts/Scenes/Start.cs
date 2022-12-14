using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Start : MonoBehaviour
{
    public void GameSceneCtrl()
    {
        SceneManager.LoadScene("Roll-a-ball"); // 게임 씬으로 이동
        Debug.Log("Game Scene Go");
    }
}
