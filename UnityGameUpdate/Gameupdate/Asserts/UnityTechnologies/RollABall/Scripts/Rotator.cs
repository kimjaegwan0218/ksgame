using UnityEngine;
using System.Collections;

public class Rotator : MonoBehaviour {

	// Before rendering each frame..
	void Update () 
	{
        // 이 스크립트가 붙은 게임오브젝트를 X축으로 15도 회전시키고,
        // Y 축에서 30, Z 축에서 45, 초당 만들기 위해 deltaTime을 곱합니다.
        // 프레임당이 아니라
        transform.Rotate (new Vector3 (15, 30, 45) * Time.deltaTime);
	}
}	